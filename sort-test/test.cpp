#include "pch.h"
#include "../Algorithm.sort/sort.h"

int getRandomNumber(int min, int max)
{
	//< 1단계. 시드 설정
	random_device rn;
	mt19937_64 rnd(rn());

	//< 2단계. 분포 설정 ( 정수 )
	uniform_int_distribution<int> range(min, max);

	//< 3단계. 값 추출
	return range(rnd);
}

const int MIN = -100, MAX = 100, SIZE = 100;


TEST(SelectionSort, Sort) {
	std::vector<int> v1, v2;
	int val = 0;
	for (int i = 0; i < SIZE; i++) {
		val = getRandomNumber(MIN, MAX);
		v1.push_back(val);
		v2.push_back(val);
	}

	SortFunctions::selectionSort(v1);
	std::sort(v2.begin(), v2.end());
  EXPECT_TRUE(std::equal(v1.begin(), v1.end(), v2.begin()));
}


TEST(BubbleSort, Sort) {
	std::vector<int> v1, v2;
	int val = 0;
	for (int i = 0; i < SIZE; i++) {
		val = getRandomNumber(MIN, MAX);
		v1.push_back(val);
		v2.push_back(val);
	}

	SortFunctions::bubbleSort(v1);
	std::sort(v2.begin(), v2.end());
	EXPECT_TRUE(std::equal(v1.begin(), v1.end(), v2.begin()));
}

TEST(InsertionSort, Sort) {
	std::vector<int> v1, v2;
	int val = 0;
	for (int i = 0; i < SIZE; i++) {
		val = getRandomNumber(MIN, MAX);
		v1.push_back(val);
		v2.push_back(val);
	}

	SortFunctions::insertionSort(v1);
	std::sort(v2.begin(), v2.end());
	EXPECT_TRUE(std::equal(v1.begin(), v1.end(), v2.begin()));
}

TEST(QuickSort, Sort) {
	std::vector<int> v1, v2;
	int val = 0;
	for (int i = 0; i < SIZE; i++) {
		val = getRandomNumber(MIN, MAX);
		v1.push_back(val);
		v2.push_back(val);
	}

	SortFunctions::quickSort(v1);
	std::sort(v2.begin(), v2.end());
	EXPECT_TRUE(std::equal(v1.begin(), v1.end(), v2.begin()));

	v1 = { 1, 1, 1, 1 };
	v2 = { 1, 1, 1, 1 };
	SortFunctions::quickSort(v1);
	std::sort(v2.begin(), v2.end());
	EXPECT_TRUE(std::equal(v1.begin(), v1.end(), v2.begin()));
}

TEST(MergeSort, Sort) {
	std::vector<int> v1, v2;
	int val = 0;
	for (int i = 0; i < SIZE; i++) {
		val = getRandomNumber(MIN, MAX);
		v1.push_back(val);
		v2.push_back(val);
	}

	SortFunctions::mergeSort(v1);
	std::sort(v2.begin(), v2.end());
	EXPECT_TRUE(std::equal(v1.begin(), v1.end(), v2.begin()));
}

TEST(HeapSort, Sort) {
	std::vector<int> v1, v2;
	int val = 0;
	for (int i = 0; i < SIZE; i++) {
		val = getRandomNumber(MIN, MAX);
		v1.push_back(val);
		v2.push_back(val);
	}

	SortFunctions::heapSort(v1);
	std::sort(v2.begin(), v2.end());
	EXPECT_TRUE(std::equal(v1.begin(), v1.end(), v2.begin()));
}