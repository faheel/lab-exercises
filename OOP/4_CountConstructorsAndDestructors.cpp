#include <iostream>

using namespace std;

class Some {
	string name;
	static int object_count;
public:
	void show_obj_count() {
		cout << "Objects alive : " << object_count << "\n";
	}

	Some(string objName) {
		name = objName;
		cout << "Object with name \'" << name << "\' created.\n";
		object_count++;
		show_obj_count();
	}

	~Some() {
		cout << "Object with name \'" << name << "\' destructed.\n";
		object_count--;
		show_obj_count();
	} 
};

int Some::object_count = 0;

int main() {
	Some obj1("First");

	{
		Some obj1("First"), obj2("Second");
	}

	Some obj3("Third");

	return 0;
}