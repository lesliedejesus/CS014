#include <iostream>
#include <cstdlib>
#include <stdlib.h>     /* srand, rand */
#include <time.h>
#include <string>
using namespace std;

//INSERTION SORT
//O(n^2)
void insertionSort(int a[], int n) { 
	int j;
	int temp;
	for (int i = 1; i < n; ++i) {
		j = i;
		while (j > 0 && a[j] < a[j - 1]) {
			temp = a[j];
			a[j] = a[j - 1];
			a[j - 1] = temp;
			--j;
		}
	}
}

//QUICKSORT
//typically O(N log N)
//but worst-case is O(N^2)
int partition(int a[], int i, int k) {
	int l = 0;
	int h = 0;
	int midpoint = i + (k - i) / 2;
	int pivot = a[midpoint];
	l = i;
	h = k;
	bool done = false;

	while (!done) {
		while (a[l] < pivot) {
			++l;
		}
		while (pivot < a[h]) {
			--h;
		}
		if(l >= h) {
			done = true;
		}
		else {
			int temp = a[l];
			a[l] = a[h];
			a[h] = temp;
			++l;
			--h;
		}
	}
	return h;
}
void quicksort(int a[], int i, int k) {
	int j = 0;

	if (i >= k) {
		return;
	}
	j = partition(a, i, k);
	quicksort(a, i, j);
	quicksort(a, j + 1, k);

}

//HEAPSORT
//worst-case O(N log N)
void heapify(int arr[], int n, int i){
	int largest = i; 
	int l = 2 * i + 1; 
	int r = 2 * i + 2; 

	if (l < n && arr[l] > arr[largest])
		largest = l;

	if (r < n && arr[r] > arr[largest])
		largest = r;

	if (largest != i){
		swap(arr[i], arr[largest]);
		heapify(arr, n, largest);
	}
}

void heapsort(int arr[], int n){ 
	for (int i = n / 2 - 1; i >= 0; i--)
		heapify(arr, n, i);
 
	for (int i = n - 1; i >= 0; i--){
		swap(arr[0], arr[i]);
		heapify(arr, i, 0);
	}
}


//MERGE SORT
//O(N log N)
void Merge(int A[], int start, int mid, int end) {
	int s = start;
	int m = mid + 1;
	int k = 0;
	int* Arr = new int[end];

	for (int i = start; i <= end; i++) {
		if (s > mid) {
			Arr[k++] = A[m++];
		}
		else if (m > end)   
			Arr[k++] = A[s++];

		else if (A[s] < A[m])    
			Arr[k++] = A[s++];

		else
			Arr[k++] = A[m++];
	}
	for (int p = 0; p < k; p++) {
		A[start++] = Arr[p];
	}
}

void MergeSort(int A[], int start, int end) {
	if (start < end) {
		int mid = (start + end) / 2;      
		MergeSort(A, start, mid);          
		MergeSort(A, mid + 1, end);              
		Merge(A, start, mid, end);
	}
}

void display(int vals[], int n) {
	for (int i = 0; i < n; i++) {
		cout << vals[i];
		if (i != n - 1) {
			cout << ", ";
		}
	}
	cout << endl;
}

int main() {

	return 0;

};