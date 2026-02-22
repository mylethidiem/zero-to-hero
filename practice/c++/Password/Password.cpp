#include <cmath>
#include <conio.h>
#include <iostream>


// Input the password, after input each character, the character will display
// "*".
void InputPassword() {
  std::string username = "";
  char password[10] = "";

  std::cout << "Input the user name: ";
  std::cin >> username;
  std::cout << "" << std::endl;

  // std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
  std::cout << "Input the password (9 letters): ";
  int count = 0;
  do {
    password[count] = _getch();
    _putch('*');
    // if (std::cin.get() == '\n')
    // {
    // 	std::cout << "Finish! " << std::endl;
    // 	break;
    // }

    count++;
  } while (count < 9);
  std::cout << "\n Show the password: " << password << std::endl;
  getchar();
}

int main()
{

  /*
   * Input password
   */
  // InputPassword();
  return 0;
}
