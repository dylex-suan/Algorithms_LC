#include <iostream>


// O(n) time, O(1) auxillary space
int main() {
	std::string str;
	std::cout << "Enter the string: ";
	std::cin >> str;

	int check = 0;

	for (int i = 0; i < str.size(); ++i) {
		int val = str[i] - 'a';
		if ((check & (1 << val)) > 0) { 
			std::cout << "String does not have unique characters" << std::endl;
			return 0;
		}
		check |= (1 << val);
	}

	std::cout << "String does have unique characters" << std::endl;
	return 0;
}
