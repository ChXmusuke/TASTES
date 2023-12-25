#include <vector>
#include <string>
#include <iostream>

#ifndef STOCK_H_
#define STOCK_H_

class Stock {
 private:
  const std::vector<double> &prices;
  std::vector<double>::const_iterator ticker = prices.begin();
  const std::string &symbol;

 public:
  Stock(const std::string &symbol, const std::vector<double> &prices);

  [[nodiscard]] double getPrice() const;
  void tick() { ++ticker; }
  [[nodiscard]] bool hasGoneUp() const;
  bool sessionEnded() { return prices.begin() != prices.end() and ticker == prices.end() - 1; }
  [[nodiscard]] const std::string &getSymbol() const;
};

std::ostream &operator<<(std::ostream &stream, const Stock &stock);

#endif
