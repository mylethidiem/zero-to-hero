#include <cctype>
#include <cmath>
#include <iostream>

void InputNumber(int &n) {
  do {
    std::cout << "Input number n: ";
    std::cin >> n;
  } while (n <= 0);
}

void InputChar(char &c) {
  std::cout << "Input char: ";
  std::cin >> c;

  if (iscntrl(c)) {
    std::cout << std::endl << "Control Character! We will exit program.";
    std::exit(0);
  }
}

/**
 * @brief Bài 52: Viết chương trình phân tích một số nguyên N thành tích của các
thừa số nguyên tố. vd: 18 = 3 * 3 * 2
 *
 * @return int
 */
bool isPrimeNumber(int n) {
  int i;
  if (n == 2 || n == 3) {
    return true;
  }

  if (n == 1 || (n % 2) == 0) {
    return false;
  }

  for (i = 3; i <= (int)sqrt((double)n); i += 2) {
    if (n % i == 0) {
      return false;
    }
  }
  return true;
}

void PrimeFactorsAnalyse(int n) {
  int i = 2, count = 0;
  if (n == 1) {
    std::cout << " 1 ";
    return;
  }
  while (n != 1) {
    if (n % i == 0) {
      count++;
      n /= i;
      if (n % i != 0 && n != 1) {
        std::cout << " " << i << " ^ " << count << " x ";
        i++;
        count = 0;
        while (!isPrimeNumber(i)) {
          i++;
        }
        continue;
      }
      if (n == 1) {
        std::cout << " " << i << " ^ " << count;
        break;
      }
    } else {
      i++;
      while (!isPrimeNumber(i)) {
        i++;
      }
    }
  }
}

/**
 * @brief Bài 53: Viết chương trình lặp lại nhiều lần công việc nhập một ký tự
 * và in ra mã ASCII của ký tự đó, khi nào nhập số 0 thì dừng.
 * @return int
 */
int ConvertToASCII(char c) { return (int)c; }

/**
 * @brief Bài 54: Viết chương trình tính dân số của một thành phố sau 10 năm
 * nữa, biết rằng dân số hiện nay là 6.000.000, tỉ lệ tăng dân số hàng năm
 * là 1.8% .
 *
 * @return int
 */
int PopulationAfter10Years() {
  int population, i;
  int CURRENT_POPULATION = 6000000, year = 10;
  double growthRate = 1.8f / 100.0f;
  population = CURRENT_POPULATION;
  for (i = 1; i <= year; i++) {
    population += population * growthRate;
  }
  return population;
}
/**
 * @brief
 * Bài 55: Viết chương trình lặp đi lặp lại các công việc sau:
 * - Nhập vào một ký tự trên bàn phím.
 * - Nếu là chữ thường thì in ra chính nó và chữ HOA tương ứng.
 * - Nếu là chữ HOA thì in ra chính nó và chữ thường tường ứng.
 * - Nếu là ký số thì in ra chính nó.
 * - Nếu là một ký tự điều khiển thì kết thúc chương trình
 * @return int
 */

char ToUpperCase(char c) {
  char result = c;
  if (c >= 97 && c <= 120) {
    result -= 32;
  }
  return result;
}

char ToLowerCase(char c) {
  char result = c;
  if (c >= 65 && c <= 97) {
    result += 32;
  }
  return result;
}

int ConvertCharToNumber(char c) { return (int)c; }

int main() {
  int n;
  char c;
  std::cout << "Input: " << std::endl;
  InputNumber(n);
  std::cout << "" << std::endl;
  InputChar(c);

  std::cout << "PrimeFactorsAnalyse: " << std::endl;
  PrimeFactorsAnalyse(n);
  std::cout << "" << std::endl;

  std::cout << "PopulationAfter10Years: " << std::endl;
  PopulationAfter10Years();
  std::cout << "" << std::endl;

  std::cout << "ConvertToASCII: " << ConvertToASCII(c) << std::endl;
  std::cout << "" << std::endl;

  std::cout << "ToUpperCase: " << ToUpperCase(c) << std::endl;
  std::cout << "" << std::endl;

  std::cout << "ToLowerCase: " << ToLowerCase(c) << std::endl;
  std::cout << "" << std::endl;

  return 0;
}
