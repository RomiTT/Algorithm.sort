#include "pch.h"
#include "../Algorithm.sort/sort.h"


class SortTest : public ::testing::Test {
protected:
	const int MIN = -1000, MAX = 1000, SIZE = 2000;
	std::vector<int> v1, v2;

protected:
	void SetUp() override {
		for (int i = 0; i < SIZE; i++) {
			int val = getRandomNumber(MIN, MAX);
			v1.push_back(val);
			v2.push_back(val);
		}

		std::cout << "SIZE = " << SIZE;
		std::cout << ", RANGE = " << MIN << "~" << MAX << endl;
	}

	void TearDown() override {

	}

private:
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
};



TEST_F(SortTest, selectionSort) {
	SortFunctions::selectionSort(v1);
	std::sort(v2.begin(), v2.end());
  EXPECT_TRUE(std::equal(v1.begin(), v1.end(), v2.begin()));
}


TEST_F(SortTest, BubbleSort) {
	SortFunctions::bubbleSort(v1);
	std::sort(v2.begin(), v2.end());
	EXPECT_TRUE(std::equal(v1.begin(), v1.end(), v2.begin()));
}

TEST_F(SortTest, InsertionSort) {
	SortFunctions::insertionSort(v1);
	std::sort(v2.begin(), v2.end());
	EXPECT_TRUE(std::equal(v1.begin(), v1.end(), v2.begin()));
}

TEST_F(SortTest, QuickSort) {
	SortFunctions::quickSort(v1);
	std::sort(v2.begin(), v2.end());
	EXPECT_TRUE(std::equal(v1.begin(), v1.end(), v2.begin()));
}

TEST_F(SortTest, MergeSort) {
	SortFunctions::mergeSort(v1);
	std::sort(v2.begin(), v2.end());
	EXPECT_TRUE(std::equal(v1.begin(), v1.end(), v2.begin()));
}

TEST_F(SortTest, HeapSort) {
	SortFunctions::heapSort(v1);
	std::sort(v2.begin(), v2.end());
	EXPECT_TRUE(std::equal(v1.begin(), v1.end(), v2.begin()));
}