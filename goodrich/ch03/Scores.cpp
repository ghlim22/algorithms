#include "Scores.hpp"
#include "Game.hpp"
#include <stdexcept>

Scores::Scores(int maxEnt)
    : _maxEntries(maxEnt), _numEntries(0), _entries(new GameEntry[maxEnt]) {}

Scores::~Scores() { delete[] _entries; }

void Scores::add(const GameEntry &e) {
  if (_maxEntries == 0)
    return;
  int newScore = e.getScore();
  if (_numEntries == _maxEntries) {
    if (_entries[_numEntries - 1].getScore() >= newScore)
      return;
  } else {
    _numEntries++;
  }

  int i = _numEntries - 2;
  while (i >= 0 && _entries[i].getScore() < newScore) {
    _entries[i + 1] = _entries[i];
    i--;
  }
  _entries[i + 1] = e;
}

GameEntry Scores::remove(int i) {
	if (i < 0 || i >= _numEntries) {
		throw std::out_of_range("Invalid index");
	}

	GameEntry e = _entries[i];
	for (int j = i + 1; j < _numEntries; ++j) {
		_entries[j - 1] = _entries[j];
	}
	_numEntries--;
	return e;																				
}
