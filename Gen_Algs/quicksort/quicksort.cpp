#include <iostream>
#include <vector>

#define MAX_NUMS 10000

int partition(int a[], int p, int n) {
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

int main() {
	int A[MAX_NUMS];
	int num;
	int n = 0;

	std::cout << "Enter your numbers: ";
	while (std::cin >> num) {
		A[n] = num;
		n++;
	}

	int part = partition(A, n/2, n); // some random pivot I suppose for p
	std::cout << "Here's what's A looks like now: ";
	for (int i = 0; i < n; ++i) {
		std::cout << A[i];
		if (i + 1 < n) {
			std::cout << " ";
		} else {
			std::cout << std::endl;
		}
	}
	std::cout << "Here's the partition at i: " << part << std::endl;
	return 0;
}
