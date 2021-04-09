#include <iostream>
using namespace std;

void createHeap(int* arr, int size);
void heapInsert(int* arr, int n);
void heapDelete(int* arr, int sizeOfHeap);
void heapSort(int* arr, int sizeOfHeap);

int main() {
    int arr[7] = { 10,20,30,25,5,40,35 };
    cout << "Original array: ";
    for (int i = 0; i < 7; i++)
        cout << arr[i] << " ";
    createHeap(arr, 7);
    cout << endl << "Heap has been created: ";
    for (int ii = 0; ii < 7; ii++)
        cout << arr[ii] << " ";
    cout << endl << "Heap Sort performed on Heap: ";
    heapSort(arr, 7);
    for (int iii = 0; iii < 7; iii++)
        cout << arr[iii] << " ";
    cout << endl;
    return 0;
}

void createHeap(int* arr, int size) {
    for (int i = 1; i < size; i++)
        heapInsert(arr, i);
}

void heapInsert(int* arr, int n) {
    int temp, i = n;
    temp = arr[n];
    while (i > 0 && temp > arr[(i-1)/2]) {
        arr[i] = arr[(i-1)/2];
        i = (i-1)/2;
    }
    arr[i] = temp;
}

// Delete function is encompassed
void heapDelete(int* arr, int sizeOfHeap) {
    int heapMax, i, j, n = sizeOfHeap-1;
    heapMax = arr[0];
    // Swap last element to "root"
    arr[0] = arr[n];
    i = 0; j = 2*i+1;
    while (j < n) { // Since Heap has 1 element extracted, MaxHeap will stop at index (size-2)
        if (arr[j+1] > arr[j])
            j++;
        if (arr[i] < arr[j]) {
            swap(arr[i], arr[j]);
            i = j;
            j = 2*i+1;
        }
        else
            break;
    }
    // Swapping heapMax into arr[n] to get sorting effect
    arr[n] = heapMax;
}

void heapSort(int* arr, int sizeOfHeap) {
    int temp = sizeOfHeap;
    while (temp > 1) {
        heapDelete(arr, temp);
        temp--;
    }
}
