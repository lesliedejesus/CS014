#include <iostream>
#include "Heap.h"
#include "PrintJob.h"
using namespace std;

/*Initializes an empty heap.*/
Heap::Heap() {
	numItems = 0;
}

/*Inserts a PrintJob to the heap without
violating max-heap properties.*/
void Heap::enqueue(PrintJob* item) {
	if (numItems == MAX_HEAP_SIZE) { // heap full
		return;
	}
	if (numItems == 0) { //empty heap
		arr[numItems] = item;
		++numItems;
	}
	else {
		int x = numItems;
		while (x > 0 && arr[(x - 1) / 2]->getPriority() < item->getPriority()) {
			arr[x] = arr[(x - 1) / 2];
			x = (x - 1) / 2;
		}
		arr[x] = item;
		++numItems;
	}
}

/*Removes the node with highest priority from the heap.
Follow the algorithm on priority-queue slides. */
void Heap::dequeue() {
	if (numItems == 0) {
		return;
	}
	arr[0] = arr[numItems - 1];
	numItems--;
	if (numItems == 1) {
		return;
	}
	else {
		trickleDown(0);
	}
	return;
}

/*Returns the node with highest priority.*/
PrintJob* Heap::highest() {
	if (numItems <= 0) {
		return 0;
	}
	PrintJob* p = arr[0];
	return p;
}

/*Prints the PrintJob with highest priority in the following format:
Priority: priority, Job Number: jobNum, Number of Pages: numPages
(Add a new line at the end.)*/
void Heap::print() {
	if (numItems == 0) {
		return;
	}
	cout << "Priority: " << highest()->getPriority() << ", Job Number: " << highest()->getJobNumber();
	cout << ", Number of Pages: " << highest()->getPages() << endl;
}


/*This function is called by dequeue function
	to move the new root down the heap to the
	appropriare location.*/
void Heap::trickleDown(int index) {
	int largestChild = 0;
	PrintJob* temp;

	//case with no children
	if (left(index) > numItems) {
		return;
	}

	else if (right(index) > numItems) { //one left child case
		if (arr[index]->getPriority() > arr[left(index)]->getPriority()) {
			return;
		}
		else {
			arr[left(index)] = arr[index];
			return;
		}
	}
	else {//two children
		if (arr[left(index)]->getPriority() > arr[right(index)]->getPriority()) {
			temp = arr[index];
			arr[index] = arr[left(index)];
			arr[left(index)] = temp;
			largestChild = left(index);
			trickleDown(largestChild);
		}
		else {
			temp = arr[index];
			arr[index] = arr[right(index)];
			arr[right(index)] = temp;
			largestChild = right(index);
			trickleDown(largestChild);
		}
	}

}

int Heap::parent(int i) {
	return (i - 1) / 2;
}
int Heap::left(int i) {
	return (2 * i + 1);
}
int Heap::right(int i) {
	return (2 * i + 2);
}