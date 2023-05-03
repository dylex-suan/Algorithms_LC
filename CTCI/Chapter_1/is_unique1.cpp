#include <iostream>
#include <unordered_map>
#include <string>

std::unordered_map<char, int> map;

// O(n) time (worst-case, O(n^2)), O(n) auxillary space
int main() {
	std::string str;
	std::cout << "Input your string: ";
	std::cin >> str;
	
	int str_len = str.size();
	
	for (int i = 0; i < str_len; ++i) {
		if (map.contains(str[i])) {
			std::cout << "String doesn't have unique characters" << std::endl;
			return 0;
		} else {
			map[str[i]] = 1; // value doesn't really matter
		}	
	}
	std::cout << "String has unique characters" << std::endl;
	return 0;
}
