#include <iostream>
#include <cmath>

#define MAX_NUM 10000

void merge(int arr[], int left, int mid, int right, int s[]) {
	for (int i = left; i <= right; ++i) {
		s[i] = arr[i];
	}
	int i_left = left;
	int i_right = mid + 1;
	for (int k = left; k <= right; ++k) {
		if (i_left > mid) {
			arr[k] = s[i_right];
			i_right++;
		} else if (i_right > right) {
			arr[k] = s[i_left];
			i_left++;
		} else if (s[i_left] <= s[i_right]) {
			arr[k] = s[i_left];
			i_left++;
		} else {
			arr[k] = s[i_right];
			i_right++;
		}
	}

}

void mergesort(int arr[], int n, int left, int right, int *s) {
	s = new int[n];
	for (int i = 0; i < n; ++i) {
		s[i] = i;
	}
	if (right <= left) return;
	int mid = (right + left) / 2;
	mergesort(arr, n, left, mid, s);
	mergesort(arr, n, mid + 1, right, s);
	merge(arr, left, mid, right, s);
}

int main() {
	int arr[MAX_NUM];
	int n = 0;
	int num;
	while (std::cin >> num) {
		arr[n] = num;
		n++;
	}

	mergesort(arr, n, 0, n - 1, nullptr);
	
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
