#include <iostream>
#include <string>
#include <vector>
#include<ctime>
#include<stdexcept>


using namespace std;

template<typename T>
/*Passes in an index of type int and a vector of type T(T could be string, double or int).
The function returns the index of the min value starting from "index" to the end of the "vector".*/
unsigned min_index(const vector<T>& vals, unsigned index) {
	unsigned min = index;
	for (unsigned i = index+1; i < vals.size(); i++) {
		if (vals[i] < vals[min]){
			min = i;
		}
	}
	return min;
}

template<typename T>
void selection_sort(vector<T>& vals) {
	for (int i = 0; i < (int)vals.size() - 1; i++) {
		unsigned min = min_index(vals, i);
		T temp = vals[i];
		vals[i] = vals[min];
		vals[min] = temp;
	}
}

template<typename T>
T getElement(vector<T> vals, int index) {
		return vals.at(index);
}

//vector<char> createVector() {
//	int size = rand() % 26;
//	char c = 'a';
//	vector<char> vals;
//	for (int i = 0; i < size; i++){
//		vals.push_back(c);
//		c++;
//	}
//	return vals;
//}

int main() {
	//Part B
	srand(time(0));
	//vector<char> vals = createVector();
	vector<double>vals = {};
	//vector<int>vals = {};
	//char curChar;
	double curChar;
	//int curChar;
	int index;
	int numOfRuns = 10;


	selection_sort(vals);
	//selection_sort(vals);
	for (int i = 0; i < vals.size(); ++i) {
		cout << getElement(vals, i) << " ";
	}
	//while (--numOfRuns >= 0) {
	//	try {
	//		cout << "Enter a number: " << endl;
	//		cin >> index;
	//		curChar = getElement(vals, index);
	//		cout << "Element located at " << index << ": is " << curChar << endl;
	//	}
	//	catch (const out_of_range & excpt) {
	//		cerr << "Out of range exception occurred" << endl;
	//	}
	//}
	return 0;
}