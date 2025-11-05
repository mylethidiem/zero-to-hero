#include <iostream>
#include <sstream>
#include <vector>

using namespace std;

void initialSStream(std::stringstream &ss) {
  // ss << "This string is created by method using insertion operator" << " " <<
  // "C++ language" << endl;
  ss.str("This string is created by method using str() C++ language\n");
}

void outputSSString(
    std::stringstream ss) // CAN'T USE this function: don't know why
{
  cout << ss.str() << endl;
}

void example1() {
  std::stringstream os;
  os << "12345 67.89"; // insert a string of numbers into the stream

  std::string strValue; // give value into variable strValue
  os >> strValue;

  std::string strValue2;
  os >> strValue2;

  // print the numbers separated by a dash
  std::cout << strValue << " - " << strValue2 << std::endl;
}

void example2() {
  std::string data = "Le Tran Dat";
  std::stringstream spliter;

  spliter << data;

  std::vector<std::string> result;
  while (!spliter.eof()) {
    std::string str;
    spliter >> str;
    result.push_back(str);
  }

  for (int i = 0; i < result.size(); i++) {
    std::cout << result.at(i) << std::endl;
  }
}

void number_to_string() {
  std::stringstream ss;

  int nValue = 12345;
  double dValue = 67.89;
  ss << nValue << " " << dValue;

  std::string strValue1, strValue2;
  ss >> strValue1 >> strValue2;

  std::cout << strValue1 << " " << strValue2 << std::endl;
}

void string_to_number() {
  std::stringstream ss;
  ss << "12345 67.89";

  int nValue;
  double dValue;
  ss >> nValue >> dValue;

  std::cout << nValue << " " << dValue << std::endl;
}
void clear_string(stringstream ss) {
  ss.str(""); // eraser the buffer
  ss.clear(); // eraser and reset error flags
}
int main() {
  /*stringstream ss;
  initialSStream(ss);
  cout << ss.str() << endl;*/
  // example2();
  // string_to_number();
  // number_to_string();

  system("pause");
  return 0;
}
