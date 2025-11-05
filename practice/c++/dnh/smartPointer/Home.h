#ifndef __HOME_H__
#define __HOME_H__
#include "GlobalVariable.h"

class Home // Villa
{
private:
  unsigned int m_id;
  unsigned int m_numberBathroom;
  unsigned int m_numberBedroom;
  unsigned int m_numberGarage;
  float m_square;
  float m_price;
  bool m_isUsing = {false};
  Category m_useFor;

public:
  Home(unsigned int id, unsigned int numberBathroom, unsigned int numberBedroom,
       unsigned int numberGarage, float Square, float Price, bool isUsing,
       Category useFor);

  virtual ~Home();

  inline unsigned int getID() { return m_id; };

  inline void setNumberBathroom(unsigned int numberBathroom) {
    m_numberBathroom = numberBathroom;
  };
  inline unsigned int getNumberBathroom() { return m_numberBathroom; };

  inline void setNumberBedroom(unsigned int numberBedroom) {
    m_numberBedroom = numberBedroom;
  };
  inline unsigned int getNumberBedroom() { return m_numberBedroom; };

  inline void setNumberGarage(unsigned int numberGarage) {
    m_numberGarage = numberGarage;
  };
  inline unsigned int getNumberGarage() { return m_numberGarage; };

  bool checkStatus();

  void setStatus(bool isUsing);
};

#endif //__HOME_H__
