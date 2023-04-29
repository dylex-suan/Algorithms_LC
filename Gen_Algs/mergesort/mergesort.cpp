#include <iostream>
#include <cmath>

#define MAX_NUM 10000

void merge(int arr[], int left, int mid, int right, int s[]) {
	for (int i = left; i <= right; ++i) {
		s[i] = arr[i];
	}
	int i_left = left;
	int i_right = mid + 1;
	/* Think about left, mid, i_left, and i_right as the bounds of 
	the given sorted arrays.

	Left sorted array goes from i_left to mid
	Right sorted array goes from i_right to right
	*/
	for (int k = left; k <= right; ++k) {
		// first condition: you've already merged the left part of the array
		// and there are still elements on the right part of the array
		// that need to be merged
		if (i_left > mid) {
			arr[k] = s[i_right];
			i_right++;
		// second condition: the right part of the array has already been merged
		// and there are still elements on the left part that need to be merged
		} else if (i_right > right) {
			arr[k] = s[i_left];
			i_left++;
		// third condition: the element at i_left is actually smaller or equal to the element
		// at i_right, so we merge that in first and increment its index
		} else if (s[i_left] <= s[i_right]) {
			arr[k] = s[i_left];
			i_left++;
		// fourth condition: the element at i_right is actually less than the element
		// at i_left, so we merge that in last
		} else {
			arr[k] = s[i_right];
			i_right++;
		}
	}

}

void mergesort(int arr[], int n, int left, int right, int *s) {
	int s_arr[n];
	for (int i = 0; i < n; ++i) {
		s_arr[i] = i;
	}
	if (right <= left) return;
	int mid = (right + left) / 2;
	// 1. sort the left side of the array (arr)
	mergesort(arr, n, left, mid, s_arr);
	// 2. sort the right side of the array (arr)
	mergesort(arr, n, mid + 1, right, s_arr);
	// 3. merge the two parts together
	merge(arr, left, mid, right, s_arr);
}

int main() {
	int arr[MAX_NUM];
	int n = 0;
	int num;
	std::cout << "Enter your numbers here: ";
	while (std::cin >> num) {
		arr[n] = num;
		n++;
	}

	mergesort(arr, n, 0, n - 1, nullptr);
	
	std::cout << "Here's the sorted array: ";
	for (int i = 0; i < n; ++i) {
		std::cout << arr[i];
		if (i + 1 < n) {
			std::cout << " ";			
		} else {
			std::cout << std::endl;
		}
	}
	return 0;
}
