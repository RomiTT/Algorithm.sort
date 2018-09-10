#pragma once

#include <vector>
#include <functional>
#include <algorithm>
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
				if (v[j] > v[j + 1]) 
					std::swap(v[j], v[j + 1]);
			}
		}
	}

	static void insertionSort(std::vector<int>& v) {
		for (size_t i = 0; i < v.size()-1; i++) {
			for (size_t j = i + 1; j > 0; j--) {
				if (v[j] < v[j - 1]) 
					std::swap(v[j], v[j - 1]);
				else 
					break;
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
					if (!bI && i <= end && v[pivot] >= v[i])
						i++;
					else 
						bI = true;

					if (!bJ && j > start && v[pivot] <= v[j])
						j--;
					else 
						bJ = true;
				}

				if (i > j) 
					std::swap(v[pivot], v[j]);
				else if (i < j)
					std::swap(v[i], v[j]);
			}

			if (start < j) 
				qsort(v, start, j - 1);

			if (j < end) 
				qsort(v, j + 1, end);
		};

		qsort(v, 0, v.size() - 1);
	}

	static void mergeSort(std::vector<int>& v) {
		std::vector<int> temp(v.size());
		auto merge = [&temp](std::vector<int>& v, size_t start, size_t mid, size_t end) {
			if ((end - start) == 1) {
				if (v[end] < v[start]) 
					std::swap(v[start], v[end]);
				return;
			}

			size_t i = start, j = mid+1, pos = start;
			while (i <= mid && j <= end) {
				if (v[i] < v[j]) {
					temp[pos] = v[i]; i++;
				}
				else {
					temp[pos] = v[j]; j++;
				}
				pos++;
			}

			if (i > mid) {
				for (; j <= end; j++) {
					temp[pos] = v[j]; pos++;
				}
			}
			else {
				for (; i <= mid; i++) {
					temp[pos] = v[i]; pos++;
				}
			}

			for (i = start; i <= end; i++) 
				v[i] = temp[i];
		};

		std::function<void(std::vector<int>&, size_t, size_t)> sort;
		sort = [&sort, &merge](std::vector<int>& v, size_t start, size_t end) {
			if (start < end) {
				int mid = (start + end) / 2;
				sort(v, start, mid);
				sort(v, mid + 1, end);
				merge(v, start, mid, end);
			}
		};

		sort(v, 0, v.size() - 1);
	}

	static void heapSort(std::vector<int>& v) {
		for (int i = 1; i < v.size(); i++) {
			int child = i;
			do {
				int root = (child - 1) / 2;
				if (v[root] < v[child]) 
					std::swap(v[root], v[child]);
				else 
					break;
				child = root;
			} while (child != 0);
		}

		for (int i = v.size() - 1; i >= 0 ; i--) {
			std::swap(v[0], v[i]);
			int root = 0, child;
			do {
				child = 2 * root + 1;
				if (child < i - 1 && v[child] < v[child + 1]) 
					child++;
				if (child < i && v[root] < v[child]) 
					std::swap(v[root], v[child]);
				else 
					break;
				root = child;
			} while (child < i);
		}
	}
};