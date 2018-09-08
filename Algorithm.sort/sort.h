#pragma once

#include <vector>
#include <functional>
#include <iostream>

class SortFunctions {
public:
	static void selectionSort(std::vector<int>& v) {
		int min; size_t posFound = 0;
		for (size_t i = 0; i < v.size(); i++) {
			min = v[i]; posFound = i;
			for (size_t j = i; j < v.size(); j++) {
				if (v[j] < min) {
					min = v[j]; posFound = j;
				}
			}
			std::swap(v[i], v[posFound]);
		}
	}

	static void bubbleSort(std::vector<int>& v) {
		for (size_t i = 0; i < v.size(); i++) {
			for (size_t j = 0; j < v.size()- i-1; j++) {
				if (v[j] > v[j + 1]) std::swap(v[j], v[j + 1]);
			}
		}
	}

	static void insertionSort(std::vector<int>& v) {
		for (size_t i = 0; i < v.size()-1; i++) {
			for (size_t j = i + 1; j > 0; j--) {
				if (v[j] < v[j - 1]) std::swap(v[j], v[j - 1]);
				else break;
			}
		}
	}

	static void quickSort(std::vector<int>& v) {
		if (v.size() <= 1) return;

		std::function<void(std::vector<int>&, size_t, size_t)> qsort;
		qsort = [&qsort](std::vector<int>& v, size_t start, size_t end) {
			size_t pivot = start, i = start + 1, j = end;
			bool bI, bJ;
			while (i <= j) {
				bI = bJ = false;

				while (!(bI && bJ)) {
					if (i <= end && v[pivot] >= v[i] && !bI) i++;
					else bI = true;

					if (j > start && v[pivot] <= v[j] && !bJ) j--;
					else bJ = true;
				}

				if (i > j) std::swap(v[pivot], v[j]);
				else std::swap(v[i], v[j]);
			}

			if (start < j) qsort(v, start, j - 1);
			if (j < end) qsort(v, j + 1, end);
		};

		qsort(v, 0, v.size() - 1);
	}

	static void mergeSort(std::vector<int>& v) {

	}

	static void heapSort(std::vector<int>& v) {

	}
};