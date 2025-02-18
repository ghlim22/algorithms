#pragma once

#include "Game.hpp"
#include <stdexcept>

class Scores {
public:
  Scores(int maxEnt = 10);
  ~Scores();
  void add(const GameEntry &e);
  GameEntry remove(int i);

private:
  int _maxEntries;
  int _numEntries;
  GameEntry *_entries;
};
