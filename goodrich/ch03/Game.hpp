#pragma once

#include <string>
class GameEntry {
public:
  GameEntry(const std::string &n = "", int s = 0);
  const std::string &getName() const;
  int getScore() const;

private:
  std::string _name;
  int _score;
};