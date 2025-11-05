#include "Home.h"
#include <iostream>

using namespace std;

Home::Home(unsigned int id, unsigned int numberBathroom,
           unsigned int numberBedroom, unsigned int numberGarage, float Square,
           float Price, bool isUsing, Category useFor) {
  m_id = id;
  m_numberBathroom = numberBathroom;
  m_numberBedroom = numberBedroom;
  m_numberGarage = m_numberGarage;
  m_square = Square;
  m_price = Price;
  m_isUsing = isUsing;
  m_useFor = useFor;
  cout << "Home ID: " << id << endl;
}

Home::~Home() {
  // cout << "Home is not using (No one owns it)" << endl;
  // m_isUsing = false;
}

bool Home::checkStatus() {
  if (m_isUsing) {
    cout << "Home is using" << endl;
  } else {
    cout << "No one owns it" << endl;
  }
  return m_isUsing;
}

void Home::setStatus(bool isUsing) { m_isUsing = isUsing; }
