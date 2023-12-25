#include "../Position.h"

double Position::Position::value() const {
  return stock.getPrice() * shares;
}

std::ostream &operator<<(std::ostream &stream, const Position &position) {
  return stream << position.stock << "x" << position.shares << " (" << position.value() << ")";
}