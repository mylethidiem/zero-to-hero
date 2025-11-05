#include <Windows.h>
#include <iostream>
using namespace std;

int value = 3;
/// *** Date *** ///
struct Date {
  unsigned int m_dd;
  unsigned int m_mm;
  unsigned int m_yy; // 4 digits number

  Date() : m_dd(1), m_mm(1), m_yy(1900) {}

  Date(unsigned int day, unsigned int month, unsigned int year)
      : m_dd(1), m_mm(1), m_yy(1900) {
    if ((year < 1900 && year > 10000) || (month < 1 && month > 12) ||
        (day < 1 && day > 31)) {
    } else {
      m_dd = day;
      m_mm = month;
      m_yy = year;
    }
  }

  ~Date() {}

  /// Check leap year ///
  int isLeapYear(unsigned int n) {
    if (n >= 1900 && n <= 10000) {
      return ((n % 4 == 0 && n % 100 != 0) || n % 400 == 0);
    }
    cout << "Invalid input value!" << endl;
    return -1;
  }

  //// Day of month ///
  int dayOfMonth(unsigned int month, unsigned int year) {
    if (isLeapYear(year) == -1 || (month < 1 && month > 12)) {
      return -1;
    }
    switch (month) {
    case 4:
    case 6:
    case 9:
    case 11: {
      return 30;
    }
    case 2: {
      if (isLeapYear(year) == 1) {
        return 29;
      }
      return 28;
    }
    default:
      return 31;
    }
  }

  /// day after ///
  int dayAfter(Date &date) {
    if (isLeapYear(date.m_yy) == -1 || (date.m_mm < 1 && date.m_mm > 12) ||
        date.m_dd < 1) {
      return -1;
    }
    switch (date.m_mm) {
    case 4:
    case 6:
    case 9:
    case 11: {
      if (date.m_dd > 30) {
        return -1;
      } else if (date.m_dd == 30) {
        date.m_dd = 1;
        date.m_mm++;
      } else {
        date.m_dd++;
      }
      break;
    }
    case 2: {
      if (date.m_dd > 29 || (isLeapYear(date.m_yy) == 0 && date.m_dd > 28)) {
        return -1;
      }

      if ((isLeapYear(date.m_yy) && date.m_dd == 29) ||
          (isLeapYear(date.m_yy) == 0 && date.m_dd == 28)) {
        date.m_dd = 1;
        date.m_mm++;
      } else {
        date.m_dd++;
      }
      break;
    }
    default: {
      if (date.m_dd > 31) {
        return -1;
      }

      if (date.m_mm == 12 && date.m_dd == 31) {
        date.m_dd = 1;
        date.m_mm = 1;
        date.m_yy++;
      } else if (date.m_dd == 31) {
        date.m_dd = 1;
        date.m_mm++;
      } else {
        date.m_dd++;
      }

      break;
    }
    }
    return 1;
  }
  ///////////////////
};

int main() {
  Date date = Date(28, 2, 2018);
  date.dayAfter(date);
  cout << date.m_dd << endl;
  cout << date.m_mm << endl;
  cout << date.m_yy << endl;
  Sleep(3000);
  int value = 100;

  cout << "Global variable: " << ::value << endl;
  cout << "Local variable: " << value << endl;
  system("cls");
  system("pause");
  return 0;
}
