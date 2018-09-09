#include "pch.h"
#include <iostream>

int number = 9;
int v[9] = { 7, 6, 5, 8, 3, 5, 9, 1, 6 };


int main()
{
	// 힙을 구성 
	//for (int i = number-1; i > 0; i++) {
	//	int c = i;
	//	do {
	//		int root = (c - 1) / 2;
	//		if (heap[root] < heap[c]) {
	//			int temp = heap[root];
	//			heap[root] = heap[c];
	//			heap[c] = temp;
	//		}
	//		c = root;
	//	} while (c != 0);
	//}
	for (int i = 1; i < number; i++) {
		int c = i;
		do {
			int root = (c - 1) / 2;
			if (v[root] < v[c]) {
				int temp = v[root];
				v[root] = v[c];
				v[c] = temp;
			}
			else break;
			c = root;
		} while (c != 0);
	}

	int a = 10, b = 20;
	std::cout << "Before swap a(" << a << ") with b(" << b << ")" << std::endl;

	std::swap(a, b);
	std::cout << "After swap a(" << a << ") with b(" << b << ")" << std::endl;

    std::cout << "Hello World!\n"; 
}

