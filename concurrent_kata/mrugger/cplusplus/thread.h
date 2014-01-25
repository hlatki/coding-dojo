#pragma once
#include <pthread.h>
#include <functional>
#include <list>
#include <thread>
#include <memory>
#include "main.h"


typedef std::function<const accumulator(const accumulator &, const sequencer &, int)> thread_callback;


class mythread
{
public:

  static int MAX_TREE_DEPTH;
  static void set_max_tree_depth(void);

  mythread(const thread_callback func, const accumulator &acc, const sequencer &seq, int tree_depth);

  const accumulator join(void) const;


private:

  const accumulator _acc;
  const sequencer _seq;
  const thread_callback _func;
  const int _tree_depth;
  const std::unique_ptr<std::thread> _thread;

  std::shared_ptr<const accumulator> thread_result_accumulator;

  void callback(void);

};
