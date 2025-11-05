#include <iostream>
/**
 * Product: price of product, quantity
 * Customer: give money
 * Saleman: exchange money
 */
enum CurrencDenomination // VND
{
  FIVE_HUNDRED_THOUSAND = 500000,
  TWO_HUNDRED_THOUSAND = 200000,
  ONE_HUNDRED_THOUSAND = 100000,
  FIFTY_THOUSAND = 50000,
  TWENTY_THOUSAND = 20000,
  TEN_THOUSAND = 10000,
  FIVE_THOUSAND = 5000,
  TWO_THOUSAND = 2000,
  ONE_THOUSAND = 1000,
  FIVE_HUNDRED = 500
};

// Input price and the money user give
void InputPrice(float &priceOfProduct, float &moneyUserGiven) {
  do {
    std::cout << "Please input the amount user must pay: ";
    std::cin >> priceOfProduct;
    std::cout << "" << std::endl;
    std::cout << "Please input the money user give: ";
    std::cin >> moneyUserGiven;
  } while (priceOfProduct < 0.f || (moneyUserGiven - priceOfProduct) < 0.f);
}

void showNumberMoneyNote(int moneyNote, int denomination) {
  if (moneyNote == 1) {
    std::cout << "1 note " << denomination << " VND " << std::endl;
  } else if (moneyNote > 1) {
    std::cout << moneyNote << " notes " << denomination << " VND " << std::endl;
  }
}

void countMoneyNote(int &moneyNote, float &remainderExchange,
                    int denomination) {
  if ((int)remainderExchange >= denomination) {
    moneyNote = (int)remainderExchange / denomination;
    remainderExchange = remainderExchange - moneyNote * denomination;
  }
}

// The customer's balance is refunded
void exchangeMoneyNote(float exchange) {
  int fiveHundreadThousandNote = 0;
  int twoHundreadThousandNote = 0;
  int oneHundreadThousandNote = 0;
  int fiftyThousandNote = 0;
  int twentyThousandNote = 0;
  int tenThousandNote = 0;
  int fiveThousandNote = 0;
  int twoThousandNote = 0;
  int oneThousandNote = 0;
  int fiveHundreadNote = 0;
  while (exchange > 0) {
    if (exchange == 0) {
      std::cout << "Does not need to give user the exchange. " << std::endl;
    } else {
      countMoneyNote(fiveHundreadThousandNote, exchange, FIVE_HUNDRED_THOUSAND);
      countMoneyNote(twoHundreadThousandNote, exchange, TWO_HUNDRED_THOUSAND);
      countMoneyNote(oneHundreadThousandNote, exchange, ONE_HUNDRED_THOUSAND);
      countMoneyNote(fiftyThousandNote, exchange, FIFTY_THOUSAND);
      countMoneyNote(twentyThousandNote, exchange, TWENTY_THOUSAND);
      countMoneyNote(tenThousandNote, exchange, TEN_THOUSAND);
      countMoneyNote(fiveThousandNote, exchange, FIVE_THOUSAND);
      countMoneyNote(twoThousandNote, exchange, TWO_THOUSAND);
      countMoneyNote(oneThousandNote, exchange, ONE_THOUSAND);
      countMoneyNote(fiveHundreadNote, exchange, FIVE_HUNDRED);
    }
  }

  std::cout << "The amount used to change back to the customer is: "
            << std::endl;
  // It's better if using stl container
  if (fiveHundreadThousandNote == 0 && twoHundreadThousandNote == 0 &&
      oneHundreadThousandNote == 0 && fiftyThousandNote == 0 &&
      twentyThousandNote == 0 && tenThousandNote == 0 &&
      fiveThousandNote == 0 && twoThousandNote == 0 && oneThousandNote == 0 &&
      fiveHundreadNote == 0) {
    std::cout << "Customer does not need to change the money!" << std::endl;
  } else {
    showNumberMoneyNote(fiveHundreadThousandNote, FIVE_HUNDRED_THOUSAND);
    showNumberMoneyNote(twoHundreadThousandNote, TWO_HUNDRED_THOUSAND);
    showNumberMoneyNote(oneHundreadThousandNote, ONE_HUNDRED_THOUSAND);
    showNumberMoneyNote(fiftyThousandNote, FIFTY_THOUSAND);
    showNumberMoneyNote(twentyThousandNote, TWENTY_THOUSAND);
    showNumberMoneyNote(tenThousandNote, TEN_THOUSAND);
    showNumberMoneyNote(fiveThousandNote, FIVE_THOUSAND);
    showNumberMoneyNote(twoThousandNote, TWO_THOUSAND);
    showNumberMoneyNote(oneThousandNote, ONE_THOUSAND);
    showNumberMoneyNote(fiveHundreadNote, FIVE_HUNDRED);
  }
}

int main()
// int LoopAdvancemain()
{
  // input
  float priceOfProduct = 0.f, customerPaid = 0.f;
  float exchange = 0.f;

  // output
  // Amount to be paid by user
  InputPrice(priceOfProduct, customerPaid);

  exchange = customerPaid - priceOfProduct;
  std::cout << "The amount the customer has to change: " << exchange
            << std::endl;

  exchangeMoneyNote(exchange);

  return 0;
}
