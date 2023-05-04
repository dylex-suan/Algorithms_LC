// check permutation
// use hash_map
// O(n) runtime, worst-case is O(n^2) because find() can be linear in the size of the container
// O(n) auxillary space
#include <iostream>
#include <unordered_map>
#include <string>

std::unordered_map<char, int> first_hash_map;
 
int main() {
	std::string first, second;
	std::cout << "Enter the first string: ";
	std::cin >> first;
	std::cout << "Enter the second string: ";
	std::cin >> second;

	if (first.size() != second.size()) {
		std::cout << "First string is not a permutation of the second string" << std::endl;
		return 0;
	}

	for (int i = 0; i < first.size(); ++i) {
		if (first_hash_map.find(first[i]) == first_hash_map.end()) {
			first_hash_map[first[i]] = 1;
		} else {
			first_hash_map[first[i]]++;
		}
	}

	for (int i = 0; i < second.size(); ++i) {
		if (first_hash_map.find(second[i]) == first_hash_map.end()) {
			std::cout << "First string is not a permutation of the second string" << std::endl;
			return 0;
		} else {
			first_hash_map[second[i]]--;
		}
	}

	for (auto t : first_hash_map) {
		if (std::get<1>(t) != 0) {
			std::cout << "First string is not a permutation of the second string" << std::endl;
			return 0;
		}	
	}

	std::cout << "First string is a permutation of the second string" << std::endl;
	return 0;
}

