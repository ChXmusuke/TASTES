#include "../Trader.h"

Trader::Trader(double balance, Portfolio &portfolio)
    : balance(balance), portfolio(portfolio) {}

double Trader::getBalance() const {

  double sum = balance;
  for (const Position &s : portfolio) sum += s.value();

  return sum;
}

double Trader::getCashBalance() const {
  return balance;
}

Portfolio &Trader::getPortfolio() const { return portfolio; }

bool Trader::transact(size_t pIndex, double shares) {
  Position &position = portfolio[pIndex];
  double transactionValue = shares * position.stock.getPrice();
  if (shares < 0 and shares > position.shares) return false;
  if (shares > 0 and transactionValue > balance) return false;

  position.shares += shares;
  balance -= transactionValue;

  return true;
}

bool Trader::buy(size_t pIndex, double shares) {
  return transact(pIndex, shares);
}

bool Trader::sell(size_t pIndex, double shares) {
  return transact(pIndex, -shares);
}