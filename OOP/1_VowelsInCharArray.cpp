/*
	Find the number of vowels in given char array using pointer arithmetic
*/

#include <iostream>
#include <cstring>

using namespace std;

int count_vowels(char *str) {
	unsigned int length = strlen(str);
	int num_vowels = 0;

	for (size_t i = 0; i < length; i++) {
		switch (*(str + i)) {
			case 'a':
			case 'A':
			case 'e':
			case 'E':
			case 'i':
			case 'I':
			case 'o':
			case 'O':
			case 'u':
			case 'U':
				num_vowels++;
		}
	}

	return num_vowels;
}

const unsigned int MAX_LENGTH = 128;

int main() {
	char str[MAX_LENGTH];
	cout << "Enter a string : ";
	cin.getline(str, MAX_LENGTH);

	int num_vowels = count_vowels(str);
	cout << "\nNumber of vowels in the string : " << num_vowels << "\n";

	return 0;
}