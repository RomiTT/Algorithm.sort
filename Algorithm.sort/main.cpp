#include "pch.h"
#include <iostream>

int main()
{
	int a = 10, b = 20;
	std::cout << "Before swap a(" << a << ") with b(" << b << ")" << std::endl;

	std::swap(a, b);
	std::cout << "After swap a(" << a << ") with b(" << b << ")" << std::endl;

    std::cout << "Hello World!\n"; 
}

