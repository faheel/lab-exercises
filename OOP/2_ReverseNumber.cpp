/*
	Reverse the given number using a function with a return type,
	and also using a function without a return type
*/

#include <iostream>

using namespace std;

void reverse_number_no_return(int &num) {
	int reverse = 0;

	while (num) {
		reverse *= 10;
		reverse += num % 10;
		num /= 10;
	}

	num = reverse;
}

int reverse_number_return(int num) {
	int reverse = 0;

	while (num) {
		reverse *= 10;
		reverse += num % 10;
		num /= 10;
	}

	return reverse;
}

int main() {
	int num;
	cout << "Enter a number : ";
	cin >> num;

	cout << "Using a function with a return type:\n";
	cout << "The reverse of the number is : " << reverse_number_return(num) << "\n";

	cout << "Using a function without a return type:\n";
	reverse_number_no_return(num);
	cout << "The reverse of the number is : " << num << "\n";

	return 0;
}