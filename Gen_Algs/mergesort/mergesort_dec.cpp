// recreating mergesort again (but decreasing)
#include <iostream>

#define MAX_NUM 10000
void merge(int arr[], int left, int mid, int right, int n, int *s) {
	// assumption is that A[left,...., mid] is sorted and 
	// A[mid + 1, ..., right] is also sorted
	
	for (int i = left; i <= right; ++i) {
		s[i] = arr[i]; // copy the elements from arr to s temporarily
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
		} else if (s[i_left] >= s[i_right]) {
			arr[k] = s[i_left];
			i_left++;
		} else {
			arr[k] = s[i_right];
			i_right++;
		}
	}

}

void mergesort(int arr[], int left, int right, int n, int *s) {
	int s_arr[n];
	if (right <= left) return;
	int mid = (left + right) / 2;
	mergesort(arr, left, mid, n, s_arr);
	mergesort(arr, mid + 1, right, n, s_arr);
	merge(arr, left, mid, right, n, s_arr);

}
int main() {
	int arr[MAX_NUM];
	int count = 0;
	int num;

	std::cout << "Input your numbers here: ";
	while (std::cin >> num) {
		arr[count] = num;	
		count++;
	}

	mergesort(arr, 0, count-1, count, nullptr);
	
	std::cout << "Here is the sorted array: ";
	for (int i = 0; i < count; ++i) {
		std::cout << arr[i];
		if (i + 1 < count) {
			std::cout << " ";
		} else {
			std::cout << std::endl;
		}	
	}

	return 0;
}
