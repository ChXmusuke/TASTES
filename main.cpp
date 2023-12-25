#include <cstdlib>
#include <vector>

#include "classes/Trader.h"
#include "classes/Stock.h"

using namespace std;

double tradeSessionDifference(Trader &t, size_t pIndex) {
  double initialBalance = t.getBalance();
  Position &position = t.getPortfolio()[pIndex];
  Stock &stock = position.stock;

  while (!stock.sessionEnded()) {
    if (stock.hasGoneUp())
      t.sell(pIndex, position.shares / 2);
    else
      t.buy(pIndex, static_cast<int>(t.getCashBalance() / (2 * stock.getPrice())));

    cout << (stock.hasGoneUp() ? '^' : 'v') << ' ' << position << endl;
    stock.tick();
  }

  return t.getBalance() - initialBalance;
}

int main() {
  const double INITIAL_BALANCE = 1000;
  vector<double> SOL_closing_prices{92.12, 93.98, 94.78, 96.30, 95.42,
                                    93.91, 94.94, 95.26, 96.54, 97.11,
                                    97.19, 97.03, 97.62, 96.54, 97.44};

  Stock SOL("SOL", SOL_closing_prices);
  Portfolio portfolio{{SOL}};

  Trader artur(INITIAL_BALANCE, portfolio);

  cout << tradeSessionDifference(artur, 0) << " - " << (artur.getBalance() / INITIAL_BALANCE - 1) * 100 << "%" << endl;

  return EXIT_SUCCESS;
}