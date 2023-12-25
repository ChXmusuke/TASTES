#include "Stock.h"
#include <iostream>

#ifndef POSITION_H_
#define POSITION_H_

struct Position {
  Stock &stock;
  double shares = 0;

  [[nodiscard]] double value() const;
};

std::ostream &operator<<(std::ostream &stream, const Position &position);

using Portfolio = std::vector<Position>;

#endif
