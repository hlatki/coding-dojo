#pragma once
#include <memory>
#include <vector>


class mutable_match_pair_accumulator
{
private:

  std::shared_ptr<match_pair_vector> _accumulator;

  mutable_match_pair_accumulator(const mutable_match_pair_accumulator &front, const match_pair &pair);
  mutable_match_pair_accumulator(const mutable_match_pair_accumulator &front, const mutable_match_pair_accumulator &back);


public:

  mutable_match_pair_accumulator(void)
  : _accumulator(new match_pair_vector())
  {}

  mutable_match_pair_accumulator(const mutable_match_pair_accumulator &other)
  : _accumulator(other._accumulator)
  {}

  mutable_match_pair_accumulator append(const match_pair &p) const;
  mutable_match_pair_accumulator append(const mutable_match_pair_accumulator &acc) const;

  const match_pair_vector &get_vector(void) const;

};


class immutable_shared_match_pair_accumulator
{
private:

  const std::shared_ptr<const match_pair_vector> _accumulator;

  const match_pair_vector *create_accumulator(const immutable_shared_match_pair_accumulator &front, const match_pair &pair) const;
  const match_pair_vector *create_accumulator(const immutable_shared_match_pair_accumulator &front, const immutable_shared_match_pair_accumulator &back) const;

  immutable_shared_match_pair_accumulator(const immutable_shared_match_pair_accumulator &front, const match_pair &pair);
  immutable_shared_match_pair_accumulator(const immutable_shared_match_pair_accumulator &front, const immutable_shared_match_pair_accumulator &back);


public:

  immutable_shared_match_pair_accumulator(void)
  : _accumulator(new match_pair_vector())
  {}

  immutable_shared_match_pair_accumulator(const immutable_shared_match_pair_accumulator &other)
  : _accumulator(other._accumulator)
  {}

  immutable_shared_match_pair_accumulator append(const match_pair &p) const;
  immutable_shared_match_pair_accumulator append(const immutable_shared_match_pair_accumulator &acc) const;

  const match_pair_vector &get_vector(void) const;

};


class immutable_byvalue_match_pair_accumulator
{
private:

  match_pair_vector _accumulator;

  immutable_byvalue_match_pair_accumulator(const immutable_byvalue_match_pair_accumulator &front, const match_pair &pair);
  immutable_byvalue_match_pair_accumulator(const immutable_byvalue_match_pair_accumulator &front, const immutable_byvalue_match_pair_accumulator &back);


public:

  immutable_byvalue_match_pair_accumulator(void)
  {}

  immutable_byvalue_match_pair_accumulator(const immutable_byvalue_match_pair_accumulator &other)
  : _accumulator(other._accumulator)
  {}

  immutable_byvalue_match_pair_accumulator append(const match_pair &p) const;
  immutable_byvalue_match_pair_accumulator append(const immutable_byvalue_match_pair_accumulator &acc) const;

  const match_pair_vector &get_vector(void) const;

};
