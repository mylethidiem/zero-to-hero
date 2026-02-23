#include <cmath>
#include <conio.h>
#include <iostream>


//
void InputPassword() {
  std::string username = "";
  char password[10] = "";

  std::cout << "Input the user name: ";
  std::cin >> username;
  std::cout << "" << std::endl;

  std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
  std::cout << "Input the password (9 letters): ";
  int count = 0;
  char ch;
  do {
    ch = _getch();
     if (ch == 13) //ASCII of Enter
     {
     	std::cout << "\nFinish! " << std::endl;
     	break;
     }
     else
     {
         password[count] = ch;
         _putch('*');
         count++;
     }

  } while (count < 9);
  password[count] = '\0';
  std::cout << "\nShow the password: " << password << std::endl;
  _getch();
}

int main()
{

  /*
   * Input password
   */
  InputPassword();
  return 0;
}
