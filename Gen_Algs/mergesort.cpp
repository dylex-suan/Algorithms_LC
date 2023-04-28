#include <iostream>
#include <cmath>

#define MAX_NUM 10000

void merge(int arr[], int left, int mid, int right, int s[]) {
	for (int i = left; i < right; ++i) {
		s[i] = arr[i];
	}
	int i_left = left;
	int i_right = mid + 1;
	for (int k = l; k <= r; ++k) {
		if (i_left > mid) {
			A[k] = S[i_right];
			i_right++;
		} else if (i_right > right) {
			A[k] = S[i_left];
			i_left++;
		} else if (S[i_left] <= S[i_right]) {
			A[k] = S[i_left];
			i_left++;
		} else {
			A[k] = S[i_right];
			i_right++;
		}
	}

}

void mergesort(int arr[], int n, int left, int right, int s[]) {
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
	

	mergesort
	return 0;
}
