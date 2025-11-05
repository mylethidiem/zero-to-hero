#include <iostream>

#include "Customer.h"
#include "Home.h"
#include "UniquePointer.h"

using namespace std;

UniquePointer *UniquePointer::m_instance = NULL;

UniquePointer *UniquePointer::getInstance() {
  if (m_instance != NULL) {
    return m_instance;
  } else {
    m_instance = new UniquePointer();
  }
}

void UniquePointer::usingUniquePointer() {
  std::unique_ptr<Home> homeX =
      make_unique<Home>(1, 2, 3, 2, 2500, 400000, true, Category::SELL);

  cout << "homeX storage information of Home: " << homeX.get() << endl;

  Customer customerHarryPotter(1, "Harry Potter", "12, Grimmauld Hall, British",
                               25);

  cout << "Customer Harry bought this house" << endl;
  customerHarryPotter.m_HomeForSell = std::move(homeX);
  customerHarryPotter.m_HomeForSell.get()->setStatus(true);

  cout << "After sold it, homeX is empty: " << homeX.get() << endl;
}
