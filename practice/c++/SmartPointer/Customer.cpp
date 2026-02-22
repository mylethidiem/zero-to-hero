#include "Customer.h"
#include <iostream>

using namespace std;

Customer::Customer(unsigned int id, std::string name, std::string address,
                   unsigned int age) {
  m_id = id;
  m_name = name;
  m_address = address;
  m_age = age;
}

Customer::~Customer() {}
