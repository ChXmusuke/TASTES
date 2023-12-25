#ifndef TRADER_H_
#define TRADER_H_

#include "Stock.h"
#include "Position.h"
#include <vector>

class Trader {
 private:
  double balance;
  Portfolio &portfolio;

  bool transact(size_t pIndex, double shares);

 public:
  explicit Trader(double balance, Portfolio &portfolio);

  [[nodiscard]]
  double getBalance() const;
  [[nodiscard]]
  double getCashBalance() const;
  [[nodiscard]]
  Portfolio &getPortfolio() const;

  bool buy(size_t pIndex, double shares);
  bool sell(size_t pIndex, double shares);
};

#endif
