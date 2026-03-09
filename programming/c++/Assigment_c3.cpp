#include <iostream>
#include <string>

int main() {
  int number1 = 15;         // Decimal
  int number2 = 017;        // Octal
  int number3 = 0x0F;       // Hexadecimal
  int number4 = 0b00001111; // Binary
  /**
   * Program prints : Where do you live?
   * User types : Finland
   * Program prints : I've heard great things about Finland. I'd like to go
   * sometime.	 *
   */
  std::string country;
  std::cout << "Where do you live?" << std::endl;
  std::getline(std::cin, country);
  std::cout << "I've heard great things about " << country
            << ". I'd like to go sometime. " << std::endl;

  return 0;
}
