#include <iostream>
#include <string>
using namespace std;

bool isDigit(char c) {
	if (c >= '0' && c <= '9') {
		return true;
	}
	return false;
}

bool isForbidden(char c) {
	if (c == '-' || c == '(' || c == ')') {
		return true;
	}
	return false;
}

void validPolynomial(string poly) {
	int highestExp = 0;
	int tempExp;
	int tempNum;
	string tempStr;
	//TO FIND REPEATED EXP VALUES
	int expVals[10];
	int expCnt = 0;

	for (unsigned i = 0; i < poly.size(); ++i) {
		if (isDigit(poly[i]) && poly[i + 1] == 'n') {
			cout << "ERROR: Invalid Polynomial; must use *" << endl;
			return;
		}
		if (isForbidden(poly[i])) {
			cout << "ERROR: Invalid Polynomial; Polynomial contains parentheses and/or negation" << endl;
			return;
		}
		if (poly[i] == 'n') {
			if (poly[i + 1] == '^') {
				tempExp = 0;
				unsigned j = i + 2;
				for (j; j < poly.size(); ++j) {
					if ((poly[j] == '.') || isForbidden(poly[j]) || (poly[j] == 'n')) {
						//cout << "ERROR: Invalid Polynomial; Invalid exponent or negation" << endl;
						return;
					}
					if (poly[j] == '+') {
						break;
					}
				}
				tempStr = poly.substr(i + 2, j - 1);
				tempExp = stoi(tempStr);
				//CHECK IF PREVIOUSLY USED EXP
				expCnt += 1;
				expVals[expCnt - 1] = tempExp;
				for (int k = 0; k < 10; ++k) {
					if (tempExp == expVals[k]){
						cout << "There can only be one term of each degree" << endl;
						return;
					}
				}
				if (highestExp < tempExp) {
					highestExp = tempExp;
				}
			}
			else if (highestExp < 1) {
				highestExp = 1;
			}
		}
	}
	if (highestExp == 0) {
		cout << "Big O class: O(1)" << endl;
	}
	else if (highestExp == 1) {
		cout << "Big O class: O(n)" << endl;
	}
	else {
		cout << "Big O class: O(n^" << highestExp << ")" << endl;
	}
}

int main() {
	string userIn;
	cout << "Enter a valid polynomial:" << endl;
	getline(cin, userIn);
	validPolynomial(userIn);

	return 0;
}