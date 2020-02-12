#include <iostream>
using namespace std;

/* implement an integer queue class using linked-list, where the nodes are
stored sorted by ascending value of the integer they store. We call this a priority queue.
Specifically, implement enqueue and dequeue methods*/

int numItems = 0;

struct node {
	int data;
	node* next;
	node(int data) : data(data), next(0) {}
};

class queue {
	private:
		node* rear;
		node* front;

	public:
		queue() {
			front = new node(NULL);
			rear = new node(NULL);
			front->next = NULL;
			rear->next = NULL;
		}
		int peek_front() {
			return front->data;
		}

		bool isEmpty() {
			if (rear == NULL) {
				return true;
			}
			return false;
		}

		void dequeue() {
			if (isEmpty()) {
				cout << "List is empty" << endl;
			}
			else {
				if (front == NULL){
					rear = NULL;
				}
				else {
					node* item2 = front->next;
					node* item1 = front;
					front = item2;
					delete item1;
					--numItems;
				}

			}
		}

		void enqueue(int k) {//priority queue, must be in ascending order
			// Create new node 
			node* newNode = new node(k);
			if (isEmpty()) {
				front = newNode;
				rear = newNode;
				return;
			}
			for (node* currentNode = front; currentNode != NULL; currentNode = currentNode->next) {
				node* nextNode = currentNode->next;
				if (newNode->data < front->data) { //item goes in front of the list
					newNode->next = front;
					front = newNode;
				}
				else if (newNode->data > rear->data) { //item goes last
					rear->next = newNode;
					rear = newNode;
				}
				else if (newNode->data > currentNode->data && newNode->data < nextNode->data) {
					currentNode->next = newNode;
					newNode->next = nextNode;
				}
				++numItems;
				cout << "node added" << endl;
			}
				
		}


};


int main() {
	queue test;
	//test.enqueue(1);
	//test.enqueue(2);
	//test.enqueue(3);
//	test.enqueue(4);
	test.dequeue();

	//cout << "The first item on the list is " << test.peek_front() << endl;

	
	
	
	
	
	return 0;
}