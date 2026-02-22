#include <cmath>
#include <conio.h>
#include <iostream>
#include "ReadNumber.h"

/*
 * Read the number:
 * EX: 1 => One
 * 12 twelve
 * 24567 twenty four thousand five hundred sixty seven
 */


void Number::showString(std::string numberString) { std::cout << numberString; };
void Number::showNumberLower16(int number) {
    switch (number) {
    case 0: {
        showString("Zero");
    } break;
    case 1: {
        showString("One");
    } break;
    case 2: {
        showString("Two");
    } break;
    case 3: {
        showString("Three");
    } break;
    case 4: {
        showString("Four");
    } break;
    case 5: {
        showString("Five");
    } break;
    case 6: {
        showString("Six");
    } break;
    case 7: {
        showString("Seven");
    } break;
    case 8: {
        showString("Eight");
    } break;
    case 9: {
        showString("Nine");
    } break;
    case 10: {
        showString("Ten");
    } break;
    case 11: {
        showString("Eleven");
    } break;
    case 12: {
        showString("Twelve");
    } break;
    case 13: {
        showString("Thirdteen");
    } break;
    case 15: {
        showString("Fifteen");
    } break;
    }
}
void Number::showNumberLower20(int number) {
    int unit = number % 10;

    if (number < 16) {
        showNumberLower16(number);
    }
    else {
        showNumberLower16(unit);
        showString("teen");
    }
}
void Number::showNumberTwoDigitWithUnitZero(int number) {
    int dozen = number / 10;

    switch (number) {
    case 20: {
        showString("Twenty");
    } break;
    case 30: {
        showString("Thirdty");
    } break;
    case 40: {
        showString("Forty");
    }; break;
    case 50: {
        showString("Fifty");
    }; break;
    default: // 60,70,80,90
    {
        showNumberLower16(dozen);
        showString("ty");
    }
    }
}

void Number::showNumberTwoDigit(int number) {
    int dozen = number / 10;
    int unit = number % 10;
    if (number < 20) {
        showNumberLower20(number);
    }
    else {
        if (unit == 0) {
            showNumberTwoDigitWithUnitZero(number);
        }
        else {
            dozen *= 10;
            showNumberTwoDigitWithUnitZero(dozen);
            showString("-");
            showNumberLower16(unit);
        }
    }
}

void Number::showNumberThreeDigit(int number) {
    int hundred = number / 100;
    int dozen = number % 100;
    showNumberLower20(hundred);
    showString(" Hundred ");

    if (dozen != 0) {
        showNumberTwoDigit(dozen);
    }
}

void Number::showNumberFourToNineDigit(int number) {
    int firstThreeNumber = 0;
    int lastNumber = 0;
    int digit = GetNumberDigit(number);

    if (digit < 7) {
        firstThreeNumber = number / 1000;
        lastNumber = number % 1000;
    }
    else {
        firstThreeNumber = number / 1000000;
        lastNumber = number % 1000000;
    }

    int firstThreeNumberDigit = GetNumberDigit(firstThreeNumber);
    int lastNumberDigit = GetNumberDigit(lastNumber);

    if (firstThreeNumberDigit == 1) {
        showNumberLower20(firstThreeNumber);
    }
    else if (firstThreeNumberDigit == 2) {
        showNumberTwoDigit(firstThreeNumber);
    }
    else if (firstThreeNumberDigit == 3) {
        showNumberThreeDigit(firstThreeNumber);
    }

    if (digit < 7) {
        showString(" Thousand ");
    }
    else {
        showString(" Million ");
    }

    if (lastNumber == 0) {
        return;
    }

    if (lastNumberDigit == 1) {
        showNumberLower20(lastNumber);
    }
    else if (lastNumberDigit == 2) {
        showNumberTwoDigit(lastNumber);
    }
    else if (lastNumberDigit == 3) {
        showNumberThreeDigit(lastNumber);
    }
    else if (lastNumberDigit > 4) {
        showNumberFourToNineDigit(lastNumber);
    }
}

int Number::GetNumberDigit(int number)
{
    return log10(number) + 1;
}

void Number::ReadNumber() {
    std::cout << "The number " << m_value << " is read as: ";
    // 1 digit
    if (m_value < 20) {
        showNumberLower20(m_value);
    }
    // 2 digits
    else if (m_digit == 2) {
        showNumberTwoDigit(m_value);
    }
    // 3 digits
    else if (m_digit == 3) {
        showNumberThreeDigit(m_value);
    }
    // 4 => 9 digits
    else if (m_digit > 3 && m_digit < 10) {
        showNumberFourToNineDigit(m_value);
    }
    else {
        // TO DO
    }
    std::cout << "" << std::endl;
}

Number::Number() {
    
}

void Number::InputNumber()
{
    do {
        std::cout << "Input the number to read: ";
        std::cin >> m_value;
        m_digit = GetNumberDigit(m_value);
        if (m_digit > 9) {
            std::cout << "Currently, we only support number having below 10 digit. "
                << std::endl;
        }
    } while (m_value < 0 && m_digit > 9);
}

int main()
{
    /*
     * Read number
     */
    Number n = Number();
    while (true)
    {
        std::cout << "Press any key to continue or ESC to exit." << std::endl;
        int key = _getch();
        if (key == 27) {
            break;
        }
        else
        {
            n.InputNumber();
            n.ReadNumber();
        }
    }

    return 0;
}
