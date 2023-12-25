#include "../Stock.h"

Stock::Stock(const std::string &symbol, const std::vector<double> &prices) : prices(prices), symbol(symbol) {}

double Stock::getPrice() const { return *ticker; }
const std::string &Stock::getSymbol() const {
  return symbol;
}

bool Stock::hasGoneUp() const {
  return *ticker > (ticker == prices.begin() ? 0 : *(ticker - 1));
}

std::ostream &operator<<(std::ostream &stream, const Stock &stock) {
  return stream << stock.getSymbol() << " - " << stock.getPrice();
}