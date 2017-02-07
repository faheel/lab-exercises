/*
	A basic calculator that can add, subtract, multiply, divide and modulus two numbers -
	implemented using an inline fuction
*/

#include <iostream>

using namespace std;

template <typename T>
inline T calculate(T a, char op, T b) {
	T result;
	
	switch (op) {
		case '+':
			result = a + b;
			break;
		case '-':
			result = a - b;
			break;
		case '*':
			result = a * b;
			break;
		case '/':
			result = a / b;
			break;
		case '%':
			result = a % b;
			break;
		default:
			cout << "Invalid operator!\n";
	}

	return result;
}

int main() {
	int a, b, result;
	char op;

	cout << "Basic calculator\n";
	cout << "----------------\n";
	cout << "Available operations : [+, -, *, /, %]\n";
	cout << "Operation format : <operand> <operator> <operand>\n\n";
	cout << "Press Ctrl+Z to exit.\n\n";

	do {
		cout << ">>> ";
		cin >> a >> op >> b;

		result = calculate(a, op, b);
		cout << "  = " << result << "\n";
	} while (true);

	return 0;
}