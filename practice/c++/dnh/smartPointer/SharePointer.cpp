#include "SharePointer.h"
#include "Customer.h"
#include "Home.h"
#include <iostream>

using namespace std;

SharePointer *SharePointer::m_Instance = NULL;

SharePointer *SharePointer::getInstance() {
  if (m_Instance) {
    return m_Instance;
  } else {
    m_Instance = new SharePointer();
  }
}

void SharePointer::usingSharePointer() {
  std::shared_ptr<Home> homeForRent =
      make_shared<Home>(2, 1, 1, 1, 1500, 500, true, Category::RENT);

  Customer customerAlbus(2, "Albus Potter", "12, Grimmauld Hall, British", 18);
  Customer customerJames(3, "James Potter", "12, Grimmauld Hall, British", 20);

  customerJames.m_HomeForRent = homeForRent;
  customerAlbus.m_HomeForRent = homeForRent;
  cout << "James and Albus rented the house having ID:"
       << customerJames.m_HomeForRent.get()->getID() << endl;
}
