// implement our own sorting algorithm
#include <iostream>
#include <string>

#define MAX_CHARS 10000

void merge(char arr[], int size, int left, int mid, int right, char s[]) {
	for (int i = left; i <= right; ++i) {
		s[i] = arr[i];	
	}

	int i_left = left;
	int i_right = mid + 1;
	for (int i = left; i <= right; ++i) {
		if (i_left > mid) {
			arr[i] = s[i_right];
			i_right++;
		} else if (i_right > right) {
			arr[i] = s[i_left];
			i_left++;
		} else if (s[i_left] < s[i_right]) {
			arr[i] = s[i_left];
			i_left++;
		} else {
			arr[i] = s[i_right];
			i_right++;
		}
	}
}

void mergesort(char arr[], int size, int left, int right, char *s) {
	char s_arr[size];
	if (right <= left) return;
	int mid = (right + left) / 2;
	mergesort(arr, size, left, mid, s_arr);
	mergesort(arr, size, mid + 1, right, s_arr);
	merge(arr, size, left, mid, right, s_arr); 	

}

int main() {
	std::string first, second;
	std::cout << "Enter your first string: ";
	std::cin >> first;
	std::cout << "Enter your second string: ";
	std::cin >> second;
	
	if (first.size() != second.size()) {
		std::cout << "First string is not a permutation of the second string" << std::endl;
		return 0;
	}

	char arr1[MAX_CHARS];
	char arr2[MAX_CHARS];	

	for (int i = 0; i < first.size(); ++i) {
		arr1[i] = first[i];
		arr2[i] = second[i];
	}

	// TODO: implement mergesort algorithm
	mergesort(arr1, first.size(), 0, first.size() - 1, nullptr);
	mergesort(arr2, second.size(), 0, second.size() - 1, nullptr);
	
	for (int i = 0; i < first.size(); ++i) {
		if (arr1[i] != arr2[i]) {
			std::cout << "First string is not a permutation of the second string" << std::endl;
			return 0;
		}
	}
	
	std::cout << "First string is a permutation of the second string" << std::endl;
	return 0;
}
