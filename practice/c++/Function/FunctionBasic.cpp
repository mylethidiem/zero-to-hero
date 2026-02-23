#include <cmath>
#include <iostream>
// 1
void UpperToLowerCase(char &c) {
  if (c >= 65 && c <= 90) {
    c += 32;
  }
}

/*
ax^2 + bx + c = 0
Number of roots

>a = 0:
        >> b=0:
                >>> c = 0: Equation with infinite solutions => root = 3
                >>> c != 0: The equation has no solution => root = 0
        >> b != 0:
                x = -c / b => root = 1
>a != 0:
=> root = 2
delta = b * b - 2 * a * c
x1 = (sqrt(delta) - b) / (2 *a)
x2 = (-sqrt(delta) - b) / (2 *a)
*/

void Quadratic(float a, float b, float c, int &roots, float &root1,
               float &root2) {
  if (a == 0) {
    if (b == 0) {
      if (c == 0) {
        roots = 3;
      }
      roots = 0;
    } else {
      root1 = -c / b;
      roots = 1;
    }
  } else {
    roots = 2;
    float rootOfDelta = sqrt(b * b - 4 * a * c);

    root1 = (rootOfDelta - b) / (2 * a);
    root2 = (-rootOfDelta - b) / (2 * a);
  }
}

void SolveQuadratic() {
  float a = 0;
  float b = 0;
  float c = 0;
  float root1 = 0;
  float root2 = 0;
  int numberOfRoot = 0;

  std::cout << "Solve quadratic function ax^2 + bx + c = 0: " << std::endl;
  std::cout << std::endl << "Input the coefficient a: ";
  std::cin >> a;
  std::cout << std::endl << "Input the coefficient b: ";
  std::cin >> b;
  std::cout << std::endl << "Input the coefficient c: ";
  std::cin >> c;

  Quadratic(a, b, c, numberOfRoot, root1, root2);
  if (numberOfRoot == 3) {
    std::cout << "Equation with infinite solutions. " << std::endl;
  }
  if (numberOfRoot == 2) {
    std::cout << "Equation with 2 solutions: " << root1 << " and " << root2
              << std::endl;
  }
  if (numberOfRoot == 1) {
    std::cout << "Equation with 1 solution: " << root1 << std::endl;
  } else {
    std::cout << "Equation with no solution. " << std::endl;
  }
}
void Input4Numbers(int &a, int &b, int &c, int &d) {
  std::cout << std::endl << "Input the a: " << std::endl;
  std::cin >> a;
  std::cout << std::endl << "Input the b: " << std::endl;
  std::cin >> b;
  std::cout << std::endl << "Input the c: " << std::endl;
  std::cin >> c;
  std::cout << std::endl << "Input the d: " << std::endl;
  std::cin >> d;
}
int minOf4Number(int a, int b, int c, int d) {
  int min = a;
  if (min > b) {
    min = b;
  } else if (min > c) {
    min = c;
  } else if (min > d) {
    min = d;
  }
  return min;
}

void Swap(int &a, int &b) {
  // way 1
  int temp = a;
  a = b;
  b = temp;

  /* way 2
  a = a + b
  b = a - b
  a = a - b
  */
}

void soft4Numbers(int &a, int &b, int &c, int &d) {
  // a
  if (a > b) {
    Swap(a, b);
  }
  if (a > c) {
    Swap(a, c);
  }
  if (a > d) {
    Swap(a, d);
  }
  // b
  if (b > c) {
    Swap(b, c);
  }
  if (b > d) {
    Swap(b, d);
  }
  // c
  if (c > d) {
    Swap(c, d);
  }
}

// 2
void InputNumber(int &n) {
  do {
    std::cout << "Input the positive Integer: " << std::endl;
    std::cin >> n;
  } while (n <= 0);
}
// S1 = 1 +2 + ...+ n
int S1(int n) {
  int i = 1, sum = 0;
  for (; i <= n; i++) {
    sum += i;
  }
  return sum;
}

// S2 = 1^2 +2^2 + ...+ n^2
int S2(int n) {
  int i = 1, sum = 0;
  for (; i <= n; i++) {
    sum += i * i;
  }
  return sum;
}

// S3 = 1/1 +1/2 + ...+ 1/n
float S3(int n) {
  int i = 1;
  float sum = 0;
  for (; i <= n; i++) {
    sum += 1.0f / (float)i;
  }
  return sum;
}

// S1 = 1 * 2 * ...* n
int S4(int n) {
  int i = 1, multi = 1;
  for (; i <= n; i++) {
    multi *= i;
  }
  return multi;
}

// S5 = 1! +2! + ...+ n!
int S5(int n) {
  int i = 1, sum = 0;
  for (; i <= n; i++) {
    int j = 1, factorial = 1;
    for (; j <= i; j++) {
      factorial *= j;
    }
    sum += factorial;
  }
  return sum;
}

int main() {
  // 1
  SolveQuadratic();

  int a = 0, b = 0, c = 0, d = 0;
  Input4Numbers(a, b, c, d);
  std::cout << "Min of 4 numbers: " << minOf4Number(a, b, c, d) << std::endl;
  std::cout << "Soft: " << std::endl;
  soft4Numbers(a, b, c, d);
  std::cout << "Min of 4 numbers: " << a << " " << b << " " << c << " " << d
            << " " << std::endl;

  // 2
  int n = 0;
  InputNumber(n);
  std::cout << "S1: " << S1(n) << std::endl;
  std::cout << "S2: " << S2(n) << std::endl;
  std::cout << "S3: " << S3(n) << std::endl;
  std::cout << "S4: " << S4(n) << std::endl;
  std::cout << "S5: " << S5(n) << std::endl;

  return 0;
}
