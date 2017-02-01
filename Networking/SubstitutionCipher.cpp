#include <iostream>

using namespace std;

string substitution_cipher(const string &plain_text, const int &shift) {
	string cipher_text;

	char shifted_char;
	for (size_t i = 0; i < plain_text.size(); i++) {
		if (plain_text[i] >= 'a' and plain_text[i] <= 'z')
			shifted_char = 'a' + ((int(plain_text[i]) + shift - int('a')) % 26);
		else if (plain_text[i] >= 'A' and plain_text[i] <= 'Z')
			shifted_char = 'A' + ((int(plain_text[i]) + shift - int('A')) % 26);
		else if (plain_text[i] >= '0' and plain_text[i] <= '9')
			shifted_char = '0' + ((int(plain_text[i]) + shift - int('0')) % 10);
		else
			shifted_char = plain_text[i];
		cipher_text += shifted_char;
	}

	return cipher_text + '\0';
}

int main() {
	string plain_text;
	cout << "Enter plain text : ";
	getline(cin, plain_text);

	int shift;
	cout << "Enter shift amount : ";
	cin >> shift;

	string cipher_text = substitution_cipher(plain_text, shift);
	cout << "Cipher text : " << cipher_text << "\n";

	return 0;
}
