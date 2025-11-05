#include <iostream>

/**
 * Bài 13: Nhập vào 2 số nguyên dương x & y với điều kiện x >= 2 và y > x. In ra
 * bảng cửu chương từ x đến y theo cách trình bày sau: vd: x = 5 & y = 9 5 x  1
 * =  5  |  6 x  1 =  6  |  7 x  1 =  7  |  8 x  1 =  8  |  9 x  1 =  9  | 5 x
 * 2 = 10 |  6 x  2 = 12 |  7 x  2 = 14 |  8 x  2 = 16 |  9 x  2 = 18 | 5 x  3 =
 * 15 |  6 x  3 = 18 |  7 x  3 = 21 |  8 x  3 = 24 |  9 x  3 = 27 | 5 x  4 = 20
 * |  6 x  4 = 24 |  7 x  4 = 28 |  8 x  4 = 32 |  9 x  4 = 36 | 5 x  5 = 25 |
 * 6 x  5 = 30 |  7 x  5 = 35 |  8 x  5 = 40 |  9 x  5 = 45 | 5 x  6 = 30 |  6 x
 * 6 = 36 |  7 x  6 = 42 |  8 x  6 = 48 |  9 x  6 = 54 | 5 x  7 = 35 |  6 x  7 =
 * 42 |  7 x  7 = 49 |  8 x  7 = 56 |  9 x  7 = 63 | 5 x  8 = 40 |  6 x  8 = 48
 * |  7 x  8 = 56 |  8 x  8 = 64 |  9 x  8 = 72 | 5 x  9 = 45 |  6 x  9 = 54 |
 * 7 x  9 = 63 |  8 x  9 = 72 |  9 x  9 = 81 |
 */
void MultiplicationTable() // x >= 2, y > x
{
  int x, y;
  do {
    std::cout << "Input number x: ";
    std::cin >> x;
    std::cout << "" << std::endl;
    std::cout << "Input number y: ";
    std::cin >> y;
  } while (x < 2 || y < x);
  int i, j;
  for (i = 1; i <= 9; i++) {
    std::cout << "| ";
    for (j = x; j <= y; j++) {
      std::cout << j << " x " << i << " = " << i * j << " | ";
    }
    std::cout << "" << std::endl;
  }
}

/**
 * Bài 14: Vẽ hình chữ nhật đặc kích thước m×n bằng các dấu *.
 * vd: Nhập m, n: 4 5
 *    * * * * *
 *    * * * * *
 *    * * * * *
 *    * * * * *
 */
void Rectangle() {
  int longs, width;
  do {
    std::cout << "Input number longs: ";
    std::cin >> longs;
    std::cout << "" << std::endl;
    std::cout << "Input number width: ";
    std::cin >> width;
  } while (longs < width || width <= 0);
  int i, j;
  for (i = 1; i <= width; i++) {
    for (j = 1; j <= longs; j++) {
      std::cout << "*";
    }
    std::cout << "" << std::endl;
  }
}

/**
 * Bài 15: Vẽ hình chữ nhật rỗng kích thước m×n.
 */
void HollowRectangle() {
  int longs, width;
  do {
    std::cout << "Input number longs: ";
    std::cin >> longs;
    std::cout << "" << std::endl;
    std::cout << "Input number width: ";
    std::cin >> width;
  } while (longs < width || width <= 0);
  int i, j;
  for (i = 1; i <= width; i++) {
    if (i == 1 || i == width) {
      for (j = 1; j <= longs; j++) {
        std::cout << "*";
      }
    } else {
      std::cout << "*";
      for (j = 2; j < longs; j++) {
        std::cout << " ";
      }
      std::cout << "*";
    }
    std::cout << "" << std::endl;
  }
}

/**
 * Bài 16: Vẽ tam giác vuông cân đặc có độ dài của cạnh là a.
 */
void TriangkeRightAngle() {
  int edge;
  do {
    std::cout << "Input number longs: ";
    std::cin >> edge;
  } while (edge <= 0);
  int i, j;
  for (i = 1; i <= edge; i++) {
    for (j = 1; j <= i; j++) {
      std::cout << "*";
    }
    std::cout << std::endl;
  }
}

/**
 * Bài 17: Vẽ tam giác cân có chiều cao h.
 */
void IsoscelesTriangle() {
  int h;
  do {
    std::cout << "Input number longs: ";
    std::cin >> h;
  } while (h <= 0);
  int i, j, k;
  for (i = 0; i < h; i++) {
    for (j = 1; j <= h - i; j++) {
      std::cout << " ";
    }
    for (k = 1; k <= 2 * i + 1; k++) {
      std::cout << "*";
    }
    std::cout << std::endl;
  }
}

/**
 *Bài 18: Vẽ tam giác cân rỗng có chiều cao h.
 */
void EmptyIsoscelesTriangle() {
  int h;
  do {
    std::cout << "Input number longs: ";
    std::cin >> h;
  } while (h <= 0);
  int i, j, k;
  for (i = 0; i < h; i++) {
    if (i == h - 1) {
      std::cout << " ";
      for (k = 1; k <= 2 * i + 1; k++) {
        std::cout << "*";
      }
    } else {
      for (j = 1; j <= h - i; j++) {
        std::cout << " ";
      }
      std::cout << "*";
      for (k = 2; k < 2 * i + 1; k++) {
        std::cout << " ";
      }
      if (i != 0) {
        std::cout << "*";
      }
    }
    std::cout << std::endl;
  }
}

int main() {
  std::cout << "MultiplicationTable" << std::endl;
  MultiplicationTable();
  std::cout << "" << std::endl;

  std::cout << "Rectangle" << std::endl;
  Rectangle();
  std::cout << "" << std::endl;

  std::cout << "HollowRectangle" << std::endl;
  HollowRectangle();
  std::cout << "" << std::endl;

  std::cout << "TriangkeRightAngle" << std::endl;
  TriangkeRightAngle();
  std::cout << "" << std::endl;

  std::cout << "IsoscelesTriangle" << std::endl;
  IsoscelesTriangle();
  std::cout << "" << std::endl;

  std::cout << "EmptyIsoscelesTriangle" << std::endl;
  EmptyIsoscelesTriangle();
  std::cout << "" << std::endl;

  return 0;
}
