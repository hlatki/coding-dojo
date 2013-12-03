#include <iostream>
#include <sstream>
#include <string>
#include <map>
#include "poker.h"

using namespace std;


string get_name (istringstream & input)
{
    string name;

    input >> name;
    name.erase (name.size() - 1);

    return name;
}

string get_hand (istringstream & input)
{
    string hand;

    for (int i = 0; i < 5; ++i)
    {
        string card;
        input >> card;
        hand += card + " ";
    }

    return hand;
}

inline char to_text (char c) { return "0123456789TJQKA"[int (c)]; }

string convert (const string & s)
{
    string result (s.size (), 0);
    transform (s.begin (), s.end (), result.begin (), to_text);
    return result;
}

string hand_to_text (const string & value,
                  size_t         high_card_index)
{
    string result = convert (value.substr (7));

    if (high_card_index < 5)
    {
        result.insert (high_card_index + 1, ">");
        result.insert (high_card_index    , "<");
    }

    return result;
}

typedef map<Evaluation, string> PossibleHands;

string get_hand_description (const Evaluation & value)
{
    PossibleHands possibilities;

    possibilities["001" ] = "high card";
    possibilities["002" ] = "pair";
    possibilities["0022"] = "two pair";
    possibilities["003" ] = "three of a kind";
    possibilities["01"  ] = "straight";
    possibilities["10"  ] = "flush";
    possibilities["1032"] = "full house";
    possibilities["104" ] = "four of a kind";
    possibilities["11"  ] = "straight flush";

    PossibleHands::iterator it = --possibilities.upper_bound (convert (value));

    return it->second;
}

int main ()
{
    string line;

    while (! getline (cin, line).eof ())
    {
        istringstream input (line);

        string name1  = get_name (input);
        string hand1  = get_hand (input);
        string value1 = evaluate (hand1);
        string description1 = get_hand_description (value1);

        string name2  = get_name (input);
        string hand2  = get_hand (input);
        string value2 = evaluate (hand2);
        string description2 = get_hand_description (value2);

        if (description1 == description2)
        {
            size_t nonmatch = mismatch (value1.begin(), value1.end (), value2.begin()).first - value1.begin () - 7;
            description1 += string() + " (" + hand_to_text (value1, nonmatch) + ")";
            description2 += string() + " (" + hand_to_text (value2, nonmatch) + ")";
        }

        if (value1 == value2)
            cout << "It's a tie. - " << description1 << " ties " << description2 << endl;
        else if (value1 > value2)
            cout << name1 << " wins. - " << description1 << " beats " << description2 << endl;
        else
            cout << name2 << " wins. - " << description2 << " beats " << description1 << endl;
    }
}

