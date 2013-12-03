#include <set>
#include "poker.h"

using namespace std;

#define ALL(a)  a.begin (), a.end ()

typedef pair<char, char> Quantity;  // (4,8) means four eights
inline char first  (const Quantity & q) { return q.first ; }
inline char second (const Quantity & q) { return q.second; }

typedef set<Quantity, greater<Quantity> > Inventory;
inline void note (Inventory & s, char c, char i) { if (c > 0) s.insert (Quantity (c, i)); }
inline void take (Inventory & s, const string & n, const string & h)
{
    for (size_t i = 0; i < n.size (); ++i)
        note (s, count (ALL (h), n[i]), i);
}

Evaluation evaluate (const Hand & cards)
{
    Inventory suit_inv; take (suit_inv, "HDCS"           , cards);  // "3C AS 3H 2C 8C" -> [(3,2)(1,0)(1,3)]
    Inventory rank_inv; take (rank_inv, "0123456789TJQKA", cards);  // "3C AS 3H 2C 8C" -> [(2,3)(1,e)(1,8)(1,2)]

    string counts (5, 0); transform (ALL (rank_inv), counts.begin (), first );  // [(2,3)(1,e)(1,8)(1,2)] -> [21110]
    string ranks  (5, 0); transform (ALL (rank_inv), ranks .begin (), second);  // [(2,3)(1,e)(1,8)(1,2)] -> [3e820]

    bool four_of_a_kind = (4 == counts[0]);
    bool full_house     = (3 == counts[0] && 2 == counts[1]);
    bool flush          = (1 == suit_inv.size ());
    bool straight       = (5 == rank_inv.size () && 5 == ranks[0] - ranks[4] + 1);

    return Evaluation () + char (four_of_a_kind || full_house || flush) + char (straight) + counts + ranks;
}

