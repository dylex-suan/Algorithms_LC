#include <iostream>
#include <vector>

#define MAX_NUMS 10000

int choose_pivot(int n) {
	return n - 1; // choose the rightmost pivot in the array
}

void swap(int & first, int & second) {
	int tmp = first;
	first = second;
	second = tmp;
}

// O(n) runtime, and O(1) space (we use the same array)
int partition_new(int a[], int p, int n, int left, int right) {
	swap(a[right], a[p]);
	int i = -1;
	int j = right;
	int v = a[right];	
	while (true) {
		do {
			++i;
		} while (a[i] < v);
		do {
			--j;
		} while (j >= i && a[j] > v);
		if (i >= j) break;
		swap(a[i], a[j]);
	}
	swap(a[right], a[i]);
	return i;
}

// O(n) runtime, but O(n) space
int partition_old(int a[], int p, int n) {
	// how to partition?
	std::vector<int> smaller;
	std::vector<int> equal;
	std::vector<int> larger;

	int v = a[p];
	for (int i = 0; i < n; ++i) {
		if (a[i] < v) { 
			smaller.push_back(a[i]);
		} else if (a[i] > v) {
			larger.push_back(a[i]);
		} else {
			equal.push_back(a[i]);
		}
	}

	int x = smaller.size();
	int y = equal.size();
	
	int i = 0;
	int curr = 0;
	for (; i < x; ++i) {
		a[i] = smaller[curr];	
		curr++;
	}
	curr = 0;
	for (; i < x + y; ++i) {
		a[i] = equal[curr];
		curr++;
	}
	curr = 0;
	for (; i < n; ++i) {
		a[i] = larger[curr];
		curr++;
	}	
	return x;
}

// O(n log n) worst case
void quicksort(int arr[], int n, int left, int right) {
	if (n <= 1) return;
	int p = choose_pivot(right);
	int i = partition_new(arr, p, n, left, right);
	quicksort(arr, i, 0, i - 1);
	quicksort(arr, (n-1) - i, i + 1, n - 1);
}

int main() {
	int A[MAX_NUMS];
	int num, k, pivot;
	int n = 0;

	std::cout << "Enter your numbers: ";
	while (std::cin >> num) {
		A[n] = num;
		n++;
	}

	quicksort(A, n, 0, n-1); // quicksort algo

	std::cout << "Here's what's A looks like now: ";
	for (int i = 0; i < n; ++i) {
		std::cout << A[i];
		if (i + 1 < n) {
			std::cout << " ";
		} else {
			std::cout << std::endl;
		}
	}
	return 0;
}
