#include <iostream>
#include "Windows.h"

void vehcn(int dai, int rong)
{
	for (int i = 0; i < rong; i++)
	{
		for (int j = 0; j < dai; j++)
		{
			std::cout << "*";
		}
		std::cout << std::endl;
	}
}

void vehcnrong(int dai, int rong)
{
	int i;
	for (i = 0; i < rong; i++)
	{
		int j;
		if (i == 0 || i == rong - 1)
		{
			for (j = 0; j < dai; j++)
			{
				std::cout << "*";
			}
		}
		else {
			for (j = 0; j < dai; j++)
			{
				if (j == 0 || j == dai - 1)
				{
					std::cout << "*";
				}
				else
				{
					std::cout << " ";
				}
			}
		}
		std::cout << std::endl;
	}
}

void veTamGiacVuongCan(int canh)
{
	for (int i = 0; i < canh; i++)
	{
		for (int j = 0; j <= i; j++)
		{
			std::cout << "*";
		}
		std::cout << std::endl;
	}
}

void VeTamGiacCanRong(int h)
{
	// Vòng lặp i chạy từ tầng 1 đến h
	for (int i = 1; i <= h; i++) {

		// Vòng lặp 1: In khoảng trắng để đẩy dấu sao vào giữa
		// số khoảng trắng h - i
		for (int j = 1; j <= (h - i); j++) {
			std::cout << " ";
		}

		// Vòng lặp 2: In số lượng dấu sao tương ứng với tầng i: 2*i - 1
		for (int k = 1; k <= (2 * i - 1); k++) {
			if (k == 1 || k == (2 * i - 1) || i == h)
			{
				std::cout << "*";
			}
			else
			{
				std::cout << " ";
			}
		}

		std::cout << std::endl;
	}
}

int main()
{
	std::cout << "ve hinh chu nhat \n";
	vehcn(5, 3);

	std::cout << "ve hinh chu nhat rong \n";
	vehcnrong(7, 4);

	std::cout << "ve tam giac vuong can \n";
	veTamGiacVuongCan(9);

	std::cout << "ve tam giac can \n";
	VeTamGiacCanRong(9);

	system("pause");
	return 0;
}