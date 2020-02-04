#include <iostream>

using namespace std;


const int NUMBERS_SIZE = 50000;
const int CLOCKS_PER_MS = CLOCKS_PER_SEC/1000; //clock per milliseconds

int genRandInt(int low, int high) {
    return low + rand() % (high - low + 1);
}
void fillArrays(int arr1[], int arr2[],int arr3[]){
    for(int i = 0; i < NUMBERS_SIZE; ++i){
        arr1[i] = genRandInt(0,NUMBERS_SIZE);
        arr2[i] = arr1[i];
        arr3[i] = arr1[i];
    }
}

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

void Quicksort_midpoint(int numbers[], int i, int k){
    int j = 0;

    if (i >= k) {
        return;
    }
    j = partition(numbers, i, k);
    Quicksort_midpoint(numbers, i, j);
    Quicksort_midpoint(numbers, j + 1, k);
}
//this function sorts the given array in the range from i to k using quicksort method.
//In this function, pivot is the midpoint element (numbers[(i+k)/2]).
int partition_medianOfThree(int a[], int i, int k) {
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
void Quicksort_medianOfThree(int numbers[], int i, int k){
    int j = 0;

    if (i >= k) {
        return;
    }
    j = partition_medianOfThree(numbers, i, k);
    Quicksort_medianOfThree(numbers, i, j);
    Quicksort_medianOfThree(numbers, j + 1, k);
}
//this function utilizes different pivot selection technique in quicksort algorithm.
//The pivot is the median of the following three values: leftmost (numbers[i]),
// midpoint (numbers[(i+k)/2]) and rightmost (numbers[k]). You should modify the
// partition function given in section 21.5 to select the pivot using median-of-three technique.
void InsertionSort(int numbers[], int numbersSize){
    int j;
    int temp;
    for (int i = 1; i < numbersSize; ++i) {
        j = i;
        while (j > 0 && numbers[j] < numbers[j - 1]) {
            temp = numbers[j];
            numbers[j] = numbers[j - 1];
            numbers[j - 1] = temp;
            --j;
        }
    }
}

int main() {
    clock_t Start = clock();
    //call sort function here
    clock_t End = clock();
    int elapsedTime = (End - Start)/CLOCKS_PER_MS; // converts elapsed time from microseconds to milliseconds.

    return 0;
}