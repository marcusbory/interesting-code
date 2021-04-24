#include <iostream>
using namespace std;

void heapify(int* arr, int sizeOfHeap);
void heapDelete(int* arr, int sizeOfHeap);
void heapSort(int* arr, int sizeOfHeap);

int main() {
    int arr[7] = { 5,10,30,20,35,40,15 };
    cout << "Original array: ";
    for (int i = 0; i < 7; i++)
        cout << arr[i] << " ";
    heapify(arr, 7);
    cout << endl << "HEAPIFY: ";
    for (int ii = 0; ii < 7; ii++)
        cout << arr[ii] << " ";
    cout << endl << "Heap Sort performed on Heap: ";
    heapSort(arr, 7);
    for (int iii = 0; iii < 7; iii++)
        cout << arr[iii] << " ";
    cout << endl;
    return 0;
}

void heapify(int* arr, int sizeOfHeap){
    // Ignore all leaf nodes
    int i = sizeOfHeap/2 -1;
    for (; i >= 0; i--) {
        // Check children of parents
        int j = 2*i+1;
        while (j < sizeOfHeap-1) {
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
    }
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
