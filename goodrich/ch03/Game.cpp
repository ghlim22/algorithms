#include "Game.hpp"

GameEntry::GameEntry(const std::string &n, int s) : _name(n), _score(s) {}

const std::string &GameEntry::getName() const { return _name; }

int GameEntry::getScore() const { return _score; }