#include <Windows.h>
#include <cmath>
#include <conio.h>
#include <fcntl.h>
#include <io.h>
#include <iomanip>
#include <iostream>
#include <string>

/**
 * ĐỀ BÀI:
 * @brief Ở Việt Nam, khi tính tiền hóa đơn, ngoài việc viết số tiền bằng các
 * con số, người ta thường hay viết kèm số tiền bằng chữ để tránh các sai sót do
 * đọc nhầm. Ví dụ:
 * - Viết bằng số: 24500
 * - Viết bằng chữ: hai mươi bốn nghìn năm trăm
 * Cho một số nguyên không âm N (0 ≤ N ≤ 999.999). Bạn hãy viết số N trên dưới
 * dạng chữ tiếng Việt. Lưu ý: sử dụng Tiếng Việt chuẩn trong các trường hợp
 * sau:
 * - 40: bốn mươi (không viết là bốn chục).
 * - 406: bốn trăm lẻ sáu (không viết là bốn trăm linh sáu hoặc bốn trăm không
 * sáu).
 * - 4006: bốn nghìn không trăm lẻ sáu (không viết là bốn ngàn không trăm lẻ
 * sáu).
 * - Chú ý các trường hợp của số 1(mốt, một), số 5 (năm, lăm).
 * Dữ liệu nhập:
 * - Là số nguyên N (0 ≤ N ≤ 999.999)
 * Dữ liệu xuất:
 * - Gồm một dòng kết quả là chuỗi tiếng Việt viết thường và không dấu, mỗi từ
 * cách nhau một khoảng trắng.
 * @return int
 */

/**
 *
vd: Giả sử nhập vào số = 123,456,789,987
123 => mot tram hai muoi ba <ty>
456 => bon tram nam muoi sau <trieu>
789 => bay tram tam muoi chin <nghin>
987 => chin tram tam muoi bay
 *
 */

/**
 * PHAN TICH 2:
số dấu phẩy = (số lượng chữ số - 1) / 3
số cụm = số dấu phẩy + 1

123456789987 => có 12 chữ số
số dấu phẩy = (số chữ số - 1) / 3 = 11 / 3 = 3
số cụm = số dấu phẩy + 1 = 3 + 1 = 4

123456789987 / 10^(3 * 3) = 123456789987 / 10^9 = 123
123456789987 % 10^9 = 456789987

456789987 / 10^(3 * 2) = 456789987 / 10^6 = 456
456789987 % 10^6 = 789987

789987 / 10^(3 * 1) = 789987 / 10^3 = 789
789987 % 10^3 = 987

987 / 10^(3 * 0) = 987 / 10^0 = 987 / 1 = 987
987 % 10^0 = 0 => KẾT THÚC

=====================================
123 % 10 = 3
123 / 10 = 12

12 % 10 = 2
12 / 10 = 1

1 % 10 = 1
1 / 10 = 0

123 / 10^2 = 1
123 % 10^2 = 23

23 / 10^1 = 2
23 % 10^1 = 3

3 / 10^0 = 3
3 % 10^0 = 0 => kết thúc
 * @return int
 */
void InputNumber(unsigned long long &n) {
  do {
    std::wcout << L"Nhập vô đi: ";
    std::wcin >> n;
  } while (n < 0);
}

void showString(std::wstring str) { std::wcout << str; }

void showString(int str, int fill = 0) {
  if (fill != 0) {
    _setmode(_fileno(stdout), _O_TEXT);
    std::cout << std::setfill('0') << std::setw(fill) << str;
    _setmode(_fileno(stdout), _O_U16TEXT);
  } else {
    std::wcout << str;
  }
}

int NumberOfDigits(unsigned long long n) {
  return (n == 0) ? 1 : (unsigned long long)log10((double)n) + 1;
}

void ReadOneDigit(int n) {
  switch (n) {
  case 0: {
    showString(L" không");
  }; break;
  case 1: {
    showString(L" một");
  }; break;
  case 2: {
    showString(L" hai");
  }; break;
  case 3: {
    showString(L" ba");
  }; break;
  case 4: {
    showString(L" bốn");
  }; break;
  case 5: {
    showString(L" năm");
  }; break;
  case 6: {
    showString(L" sáu");
  }; break;
  case 7: {
    showString(L" bảy");
  }; break;
  case 8: {
    showString(L" tám");
  }; break;
  case 9: {
    showString(L" chín");
  }; break;
  case 10: {
    showString(L" mười");
  }; break;
  case 15: {
    showString(L" lăm");
  }; break;
  case 21: {
    showString(L" mốt");
  }; break;
  }
}

void ReadTwoDigits(int n) {
  int numberOfDigit = 0;
  numberOfDigit = NumberOfDigits(n);
  if (numberOfDigit < 2 || n == 10) {
    ReadOneDigit(n);
    return;
  }

  int head = 0, otherDigit = 0;
  head = n / 10;
  otherDigit = n % 10;

  if (head == 1) {
    showString(L" mười");
    if (otherDigit == 5) {
      otherDigit = 15;
    }
    ReadOneDigit(otherDigit);
  } else {
    ReadOneDigit(head);
    showString(L" mươi");

    if (otherDigit != 0) {
      if (otherDigit == 1) {
        otherDigit = 21;
      } else if (otherDigit == 5) {
        otherDigit = 15;
      }
      ReadOneDigit(otherDigit);
    }
  }
}

void ReadThreeDigits(unsigned long long n) {
  unsigned long long numberOfDigit = 0;
  numberOfDigit = NumberOfDigits(n);
  if (numberOfDigit < 3) {
    ReadTwoDigits(n);
    return;
  }

  unsigned long long head = 0, otherDigit = 0;
  head = n / 100;
  otherDigit = n % 100;

  ReadOneDigit(head);
  showString(L" trăm");
  if (otherDigit != 0) {
    if (NumberOfDigits(otherDigit) == 1) {
      showString(L" lẻ");
    }
    ReadTwoDigits(otherDigit);
  }
}

void ReadRemainNumbers(unsigned long long numberOfDigits) {
  if (numberOfDigits % 3 ==
      1) //(numberOfDigits == 1 || numberOfDigits == 4 || numberOfDigits == 7)
  {
    ReadOneDigit(0);
    showString(L" trăm lẻ");
  } else if (numberOfDigits % 3 == 2) //(numberOfDigits == 2 || numberOfDigits
                                      //== 5 || numberOfDigits == 8)
  {
    ReadOneDigit(0);
    showString(L" trăm");
  }
}
void ShowNumberWithDotma(unsigned long long n) {
  unsigned long long dotma = 0, numberOfDigits = 0, head = 0, otherDigits = 0,
                     powResult = 0, temp = 0;
  temp = n;
  numberOfDigits = NumberOfDigits(n);

  if (numberOfDigits < 4) {
    showString(n);
    return;
  }
  dotma = (unsigned long long)(numberOfDigits - 1) / 3;

  while (dotma != 0) {
    if (dotma > 3) {
      powResult = (unsigned long long)pow(10, 3 * 3);
      head = (unsigned long long)n / powResult;
      if (head != 0) {
        ShowNumberWithDotma(head);
        showString(L",");
      }
    } else {
      powResult = (unsigned long long)pow(10, dotma * 3);
      head = (unsigned long long)n / powResult;
      if (head != 0) {
        if (temp == n) {
          showString(head, 0);
        } else {
          showString(head, 3);
        }
        showString(L",");
      }
    }
    numberOfDigits = NumberOfDigits(n);
    n = (unsigned long long)n % powResult;
    dotma--;
    if (dotma == 0) {
      showString(n, 3);
      return;
    }
  }
}

void ReadNumber(unsigned long long n) {
  unsigned long long numberOfDigit = 1;
  int dotma = 0;
  numberOfDigit = NumberOfDigits(n);
  if (numberOfDigit < 4) {
    ReadThreeDigits(n);
    return;
  }

  unsigned long long head, powResult = 0, otherDigit = 0;
  unsigned long long temp = n;
  dotma = (int)(NumberOfDigits(temp) - 1) / 3;

  while (dotma >= 0) {
    dotma = (int)(NumberOfDigits(temp) - 1) / 3;
    if (dotma > 3) {
      powResult = (unsigned long long)pow(10, 3 * 3);
      head = (unsigned long long)temp / powResult;
      ReadNumber(head);
      showString(L" tỷ");
    } else {
      powResult = (unsigned long long)pow(10, dotma * 3);
      head = (unsigned long long)temp / powResult;
      if (head != 0) {
        if (temp != n) {
          unsigned long long headDigits = NumberOfDigits(head);
          if (headDigits < (numberOfDigit - 1)) {
            ReadRemainNumbers(headDigits);
          }
          ReadThreeDigits(head);
        } else {
          ReadThreeDigits(head);
        }
      }
    }

    if (dotma == 1) {
      showString(L" nghìn");
    } else if (dotma == 2) {
      showString(L" triệu");
    } else if (dotma == 3) {
      showString(L" tỷ");
    }

    numberOfDigit = NumberOfDigits(temp);
    temp = (unsigned long long)temp % powResult;
    dotma--;
  }
}

void InputNumberRuntime(unsigned long long &n) {
  char c;
  unsigned long long MAX_VALUE_TYPE =
      (long long int)pow(2, 8 * sizeof(n) - 1) - 1;
  while (true) {
    c = getch();
    if (c >= '0' && c <= '9' || c == 8) {
      if (c >= '0' && c <= '9') {
        // n = n * 10 + ((unsigned long long)c - 48) < MAX_VALUE_TYPE
        if (n < MAX_VALUE_TYPE - ((unsigned long long)c - 48) / 10) {
          n = n * 10 + (unsigned long long)c - 48;
        } else {
          std::wcout << L"Dữ liệu vượt qua giới hạn lưu trữ! " << n
                     << std::endl;
          Sleep(1000);
        }
      }

      if (c == 8) {
        n /= 10;
      }
      system("cls");
      showString(L"Số được viết dưới dạng số là: ");
      ShowNumberWithDotma(n);
      std::wcout << std::endl;
      showString(L"Số được viết dưới dạng chữ là: ");
      ReadNumber(n);
      std::wcout << std::endl;
    }

    // To exit, press c
    if (c == 'c') {
      showString(L"Chương trình sẽ tắt! ");
      break;
    }
  }
}

int main() {

  _setmode(_fileno(stdin), 0x00020000);
  _setmode(_fileno(stdout), 0x00020000);

  std::wcout << L"Xin chào!" << std::endl;
  unsigned long long n;
  InputNumberRuntime(n);
  // InputNumber(n);
  // showString(L"Số được viết dưới dạng số là: ");
  // ShowNumberWithDotma(n);
  // std::wcout << std::endl;
  // showString(L"Số được viết dưới dạng chữ là: ");
  // ReadNumber(n);
  return 0;
}
