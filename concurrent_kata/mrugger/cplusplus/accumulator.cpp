#include "main.h"


/***** mutable *****/


mutable_match_pair_accumulator::mutable_match_pair_accumulator(
  const mutable_match_pair_accumulator &front,
  const match_pair &pair)
: _accumulator(front._accumulator)
{
  _accumulator->push_back(pair);
}


mutable_match_pair_accumulator::mutable_match_pair_accumulator(
  const mutable_match_pair_accumulator &front,
  const mutable_match_pair_accumulator &back)
: _accumulator(front._accumulator)
{
  _accumulator->insert(_accumulator->end(),
                       back._accumulator->begin(),
                       back._accumulator->end());
}


mutable_match_pair_accumulator mutable_match_pair_accumulator::append(const match_pair &pair) const
{
  return mutable_match_pair_accumulator(*this, pair);
}


mutable_match_pair_accumulator mutable_match_pair_accumulator::append(const mutable_match_pair_accumulator &acc) const
{
  return mutable_match_pair_accumulator(*this, acc);
}


const match_pair_vector &mutable_match_pair_accumulator::get_vector(void) const
{
  return *_accumulator;
}


/***** immutable shared *****/


immutable_shared_match_pair_accumulator::immutable_shared_match_pair_accumulator(
  const immutable_shared_match_pair_accumulator &front,
  const match_pair &pair)
: _accumulator(create_accumulator(front, pair))
{
}


immutable_shared_match_pair_accumulator::immutable_shared_match_pair_accumulator(
  const immutable_shared_match_pair_accumulator &front,
  const immutable_shared_match_pair_accumulator &back)
: _accumulator(create_accumulator(front, back))
{
}


const match_pair_vector *immutable_shared_match_pair_accumulator::create_accumulator(
  const immutable_shared_match_pair_accumulator &front,
  const match_pair &pair) const
{
  std::unique_ptr<match_pair_vector> new_acc(new match_pair_vector(*(front._accumulator)));
  new_acc->push_back(pair);
  return new_acc.release();
}


const match_pair_vector *immutable_shared_match_pair_accumulator::create_accumulator(
  const immutable_shared_match_pair_accumulator &front,
  const immutable_shared_match_pair_accumulator &back) const
{
  std::unique_ptr<match_pair_vector> new_acc(new match_pair_vector(*(front._accumulator)));
  new_acc->insert(new_acc->end(), back._accumulator->cbegin(), back._accumulator->cend());
  return new_acc.release();
}


immutable_shared_match_pair_accumulator immutable_shared_match_pair_accumulator::append(const match_pair &pair) const
{
  return immutable_shared_match_pair_accumulator(*this, pair);
}


immutable_shared_match_pair_accumulator immutable_shared_match_pair_accumulator::append(const immutable_shared_match_pair_accumulator &acc) const
{
  return immutable_shared_match_pair_accumulator(*this, acc);
}


const match_pair_vector &immutable_shared_match_pair_accumulator::get_vector(void) const
{
  return *_accumulator;
}


/***** immutable byvalue *****/


immutable_byvalue_match_pair_accumulator::immutable_byvalue_match_pair_accumulator(
  const immutable_byvalue_match_pair_accumulator &front,
  const match_pair &pair)
: _accumulator(front._accumulator)
{
  _accumulator.push_back(pair);
}


immutable_byvalue_match_pair_accumulator::immutable_byvalue_match_pair_accumulator(
  const immutable_byvalue_match_pair_accumulator &front,
  const immutable_byvalue_match_pair_accumulator &back)
: _accumulator(front._accumulator)
{
  _accumulator.insert(_accumulator.end(),
                      back._accumulator.begin(),
                      back._accumulator.end());
}


immutable_byvalue_match_pair_accumulator immutable_byvalue_match_pair_accumulator::append(const match_pair &pair) const
{
  return immutable_byvalue_match_pair_accumulator(*this, pair);
}


immutable_byvalue_match_pair_accumulator immutable_byvalue_match_pair_accumulator::append(const immutable_byvalue_match_pair_accumulator &acc) const
{
  return immutable_byvalue_match_pair_accumulator(*this, acc);
}


const match_pair_vector &immutable_byvalue_match_pair_accumulator::get_vector(void) const
{
  return _accumulator;
}
