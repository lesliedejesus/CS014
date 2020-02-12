#include <iostream>
using namespace std;
/*Write a C++ class that implement two stacks using a single C++ array. That is, it should have functions
popFirst(…), popSecond(…), pushFirst(…), pushSecond(…),… When out of space, double the size of the
array (similarly to what vector is doing).*/

class stack {
private:
	int top1, top2;
public:
	int a[MAX]; //max size of array
	stack() { top1 = top2 = -1; }
	int popFirst(int& a[]);
	int popSecond(int& a[]);
	void pushFirst(int x);
	void pushSecond(int a[]);
	int* grow(int a[]);
};

//pops first element from 1st stack
int popFirst(int& a[]) {
	int popped = a[0];
	for (int i = 0; i < sizeof(a)/2 - 1; ++i) {//only goes until second to last item
		a[i] = a[i + 1];
	}
	a[sizeof(a)/2 - 1] = 0;
	return popped;
}
//pops 1st element from second stack
int popSecond(int& a[]) {
	int popped = a(sizeof(a) / 2);
	for (int i = sizeof(a) / 2; i < sizeof(a) - 1; ++i) {
		a[i] = a[i + 1];
	}
	a[sizeof(a) - 1] = 0;
	return popped;
}

void pushFirst(int x) {
	if (top1 < top2 - 1) { //theres room for another item
		top++; //increase index of top?
		a(top1) = x;
	}
	else {
		grow(); //double size of array
	}
}

int* grow() {
	int length = sizeof(a); //gets initial length
	int stack2Begin = length / 2 - 1; //first content of stack 2

	int* newA = new int[2*length];
	for (int i = 0; i < stack2Begin; ++i) {//copt stack 1 elements
		newA[i] = a[i];
	}
	for (int i = length; i < sizeof(newA); i++) {//copy stack 2 elements
		new_a[i] = a[stack2Begin];
		stack2Begin++;
	}
	return newA;		
}



int main() {




	return 0;
}