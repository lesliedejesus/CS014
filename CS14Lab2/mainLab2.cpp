#include <iostream>
#include <string>
#include "IntList.h"
using namespace std;

int main() {

	IntList test;

	/*int back;
	cout << "push back" << endl;
	cin >> back;
	test.push_back(back);

	int back1;
	cout << "push back" << endl;
	cin >> back1;
	test.push_back(back1);

	int back2;
	cout << "push back" << endl;
	cin >> back2;
	test.push_back(back2);

	int front;
	cout << "push front" << endl;
	cin >> front;
	test.push_front(front);

	int front1;
	cout << "push front" << endl;
	cin >> front1;
	test.push_front(front1);

	int front2;
	cout << "push front" << endl;
	cin >> front2;
	test.push_front(front2);

	int front3;
	cout << "push front" << endl;
	cin >> front3;
	test.push_front(front3);

	test.printReverse();
	cout << endl;*/
	cout << "pop back" << endl;
	test.pop_back();
	cout << "pop front" << endl;
	test.pop_front();

	//cout << "The list is now: " << test << endl;

	if (!test.empty()) {
		cout << "List is not empty" << endl;
	}
	else {
		cout << "List is empty" << endl;
	}



	return 0;
};