#include "Stock.h"
#include "Position.h"
#include <vector>

#ifndef TRADER_H_
#define TRADER_H_

class Trader {
 private:
  double balance;
  Portfolio &portfolio;

  bool transact(size_t pIndex, int shares);

 public:
  explicit Trader(double balance, Portfolio &portfolio);

  [[nodiscard]]
  double getBalance() const;
  [[nodiscard]]
  double getCashBalance() const;
  [[nodiscard]]
  Portfolio &getPortfolio() const;

  bool buy(size_t pIndex, int shares);
  bool sell(size_t pIndex, int shares);
};

#endif
