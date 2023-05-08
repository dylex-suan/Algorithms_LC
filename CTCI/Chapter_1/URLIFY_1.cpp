#include <iostream>
#include <string>

int main() {
	int true_value, index, space_count = 0;
	std::string str;
	std::cout << "Enter your string: ";
	getline(std::cin, str);
	std::cout << "What's the true value?";
	std::cin >> true_value;
	
	int len = str.size();
	char new_str[len];
	
	for (int i = 0; i < true_value; ++i) {
		if (str[i] == ' ') space_count++;
	}
	
	index = true_value + space_count * 2;
	if (true_value < str.size()) index = true_value + space_count * 2;
	for (int i = true_value - 1; i >= 0; --i) {
		if (str[i] == ' ') {
			new_str[i - 1] = '0';
			new_str[i - 2] = '2';
			new_str[i - 3] = '%';
			index = index - 3;
		} else {
			new_str[index - 1] = str[i];
			index--;
		}	
	}
	std::cout << "Here's the new string: " << new_str << std::endl;
	return 0;
}
