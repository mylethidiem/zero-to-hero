#include <cmath>
#include <iostream>

bool isSymmetricalNumber(int n) {
  // 121, 1221...
  // 1221%10 reverse number => a[0..num-1] s = s + a[i] => compare s va n
  int reverseNumber = 0;
  int temp = n;
  while (n > 0) {
    reverseNumber = reverseNumber * 10 + n % 10;
    n = n / 10;
  }

  if (reverseNumber == temp) {
    return true;
  }
  return false;
}

bool isSquareNumber(int n) {
  // 1,4,9...
  // i=0...[sqNum (= sqrt(n))],sqNum < n/2, compare pow(i) & n%10
  if (n == 1) {
    return true;
  }

  int i = 1;
  for (; i <= n / 2; i++) {
    if ((i * i) == n) {
      return true;
    }
  }
  return false;
}
bool isSquareNumberWay2(int n) {
  // 1,4,9...
  /*
   * Compare sqrt
   */
  if (n == 1) {
    return true;
  }
  /*
   * Compare sqrt
   */
  if (sqrt((double)n) == (int)sqrt((double)n)) {
    return true;
  }

  return false;
}

bool isPrimeNumber(int n) {
  // special case:1,2,3 and ,5,7,11,13,17...
  // i=0...(n-1), if n % i == 0 => not prime
  // does not care even number
  if (n == 1) {
    return false;
  }
  if (n == 2 || n == 3) {
    return true;
  }

  // int i = (n - 1) / 2;
  int i = 3;
  if (n > 3 && (n % 2) == 0) {
    return false;
  }

  for (; i <= (int)sqrt((double)n); i += 2) {
    if (n % i == 0) {
      return false;
    }
  }
  return true;
}

bool isAscendingNumber(int n) {
  // 11, 123, 11223,...
  // remainder = n%10, n=n%10, i2 = n%10, if remainder > i2 > i3 > i4 ...true
  int remainder = n % 10;
  n = n / 10;
  while (n / 10 != 0) {
    if (remainder >= (n % 10)) // remainder > i2
    {
      remainder = n % 10;
      n = n / 10;
    } else {
      return false;
    }
  }
  return true;
}

bool isDescendingNumber(int n) {
  // 11, 321, 32211,...
  // remainder = n%10, n=n%10, i2 = n%10, if remainder < i2 < i3 < i4 ...true
  int remainder = n % 10;
  while (n / 10 != 0) {
    n = n / 10;
    if (remainder <= (n % 10)) // i1 < i2
    {
      remainder = n % 10;
    } else {
      return false;
    }
  }
  return true;
}
// check number synmetric, square, prime in [a,b]
void specialNumberIdentifier(int a, int b) {
  int synmetricNumberQuantity = 0, squareNumberQuantity = 0,
      primeNumberQuantity = 0;
  int synmetricNumberSum = 0, squareNumberSum = 0, primeNumberSum = 0;
  int i = 0;
  for (i = a; i <= b; i++) {
    if (isSymmetricalNumber(i) == true) {
      std::cout << "Symmetrical Number: " << i << " " << std::endl;
      synmetricNumberQuantity++;
      synmetricNumberSum += i;
    } else if (isSquareNumber(i) == true) {
      std::cout << "Square Number: " << i << " " << std::endl;
      squareNumberQuantity++;
      squareNumberSum += i;
    } else if (isPrimeNumber(i) == true) {
      std::cout << "Prime Number: " << i << " " << std::endl;
      primeNumberQuantity++;
      primeNumberSum += i;
    }
  }
  std::cout << " " << std::endl;
  std::cout << "Sum of Synmetrical Number: " << synmetricNumberSum << " "
            << std::endl;
  std::cout << "Sum of Square Number: " << squareNumberSum << " " << std::endl;
  std::cout << "Sum of Prime Number: " << primeNumberSum << " " << std::endl;
  std::cout << " " << std::endl;
  std::cout << "Number of Synmetrical Number: " << synmetricNumberQuantity
            << " " << std::endl;
  std::cout << "Number of Square Number: " << squareNumberQuantity << " "
            << std::endl;
  std::cout << "Number of Prime Number: " << primeNumberQuantity << " "
            << std::endl;
}

void findNumExercise3(int a, int b) {
  int i = a;
  for (; i <= b; i++) {
    int dozen = i / 10;
    int unit = i % 10;
    int multi = dozen * unit;
    int sum = 2 * (dozen + unit);

    if (multi == sum) {
      std::cout << "Number: " << i << std::endl;
    }
  }
}

/*
 * Other way: a != b
 * if a > b: a -= b
 * if b < a: b -= a
 * if a == b: return a
 */
int UCLN(int a, int b) {
  int min = (a > b) ? a : b;
  int max = (a < b) ? a : b;

  if (max == min) {
    return max;
  } else if (max % min == 0) {
    return min;
  } else {
    int i = min / 2;
    for (; i > 0; i--) {
      if ((a % i == 0) && (b % i == 0)) {
        return i;
      }
    }
  }
  return 1;
}

void Fibonacci(unsigned long long int n) {
  unsigned long long int a0 = 1;
  unsigned long long int a1 = 1, i = 0;
  std::cout << a0 << " " << a1;
  for (; i < n; i++) {
    unsigned long long int c = a1 + a0;
    a0 = a1;
    a1 = c;

    std::cout << " " << a1;
  }
}

int main()
// int LoopBasicmain()
{
  // input 1
  int n;
  std::cout << "Input number n: " << std::endl;
  std::cin >> n;
  std::cout << " " << std::endl;
  // check n
  std::cout << "isSymmetricalNumber: " << isSymmetricalNumber(n) << " "
            << std::endl;
  std::cout << "isSquareNumber: " << isSquareNumber(n) << " " << std::endl;
  std::cout << "isPrimeNumber: " << isPrimeNumber(n) << " " << std::endl;
  std::cout << "isAscendingNumber: " << isAscendingNumber(n) << " "
            << std::endl;
  std::cout << "isDescendingNumber: " << isDescendingNumber(n) << " "
            << std::endl;

  // input 2
  int a = 0, b = 0;
  do {
    std::cout << " " << std::endl;
    std::cout << "Input number a: " << std::endl;
    std::cin >> a;
    std::cout << "Input number b: " << std::endl;
    std::cin >> b;
    std::cout << " " << std::endl;
  } while (b < a);
  specialNumberIdentifier(a, b);

  // output 3
  do {
    std::cout << " " << std::endl;
    std::cout << "Input number a: " << std::endl;
    std::cin >> a;
    std::cout << "Input number b: " << std::endl;
    std::cin >> b;
    std::cout << " " << std::endl;
  } while ((a < 10 && a > 99) || (b < 10 && b > 99));
  findNumExercise3(a, b);

  // output 4
  std::cout << "UCLN is:  " << a << " & " << b << ": " << UCLN(a, b)
            << std::endl;

  // output 5
  unsigned long long int fibonacciList = 0;
  std::cout << " " << std::endl;
  std::cout << " Fibonacci list: " << std::endl;
  std::cout << "Input n number: " << std::endl;
  std::cin >> fibonacciList;
  Fibonacci(fibonacciList);

  return 0;
}
