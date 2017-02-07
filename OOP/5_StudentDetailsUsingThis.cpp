#include <iostream>

using namespace std;

void print_heading(string heading) {
	cout << heading << "\n";
	for (size_t i = 0; i < heading.length(); i++)
		cout << '-';
	cout << "\n";
}

void get_input(int &roll_no, string &name) {
	cout << "Roll no : ";
	cin >> roll_no;
	cout << "Name : ";
	cin.ignore();
	getline(cin, name);
}

class Student {
	int roll_no;
	string name;
public:
	void set_data(int roll_no, string name) {
		this->roll_no = roll_no;
		this->name = name;
	}

	void print() {
		print_heading("\nStudent datails");
		cout << "Roll no\t: " << this->roll_no << "\n";
		cout << "Name\t: " << this->name << "\n";
	}
};

int main() {
	Student s1, s2, s3;
	int roll_no;
	string name;

	print_heading("Student 1");
	get_input(roll_no, name);
	s1.set_data(roll_no, name);

	print_heading("\nStudent 2");
	get_input(roll_no, name);
	s2.set_data(roll_no, name);

	print_heading("\nStudent 3");
	get_input(roll_no, name);
	s3.set_data(roll_no, name);

	s1.print();
	s2.print();
	s3.print();

	return 0;
}