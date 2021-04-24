#include <iostream>
using namespace std;

void rHeapify(int* arr, int n, int i);
void buildHeap(int* arr, int len);
void extractMax(int* arr, int len);
void heapSort(int* arr, int len);

int main() {
    int len = 10;
    int arr[len] = { 14, 16, 28, 47, 1, 33, 24, 23, 98, 7 };
    cout << "Original Inputs: ";
    for (int i = 0; i < len; i++)
        cout << arr[i] << " ";
    cout << endl;
    
    cout << "Build a Max Heap: ";
    buildHeap(arr, len);
    for (int ii = 0; ii < len; ii++)
        cout << arr[ii] << " "; 
    cout << endl;

    cout << "Heap Sort: ";
    heapSort(arr, len);
    for (int iii = 0; iii < len; iii++)
        cout << arr[iii] << " ";
    cout << endl;

    return 0;
}

/**
 *  The reason why Heapify is faster than building a Heap
 *  through repeated insertion is because Heapify follows
 *  the bubble down approach, whereas repeated insertion 
 *  follows a bubble up approach. Using Heapify, we can 
 *  ignore all leaf nodes as they are definitely the smallest
 *  after we have bubbled them DOWN during the process of 
 *  Heapify.
 */
void rHeapify(int* arr, int n, int i) {
    int max = i;
    int lchild = (i*2)+1;
    int rchild = (i*2)+2;
    
    // Checks if lchild and rchild are within range of Heap
    // Finding the bigger child 
    if (lchild < n && arr[lchild] > arr[max])
        max = lchild;
    if (rchild < n && arr[rchild] > arr[max])
        max = rchild;
    // If max has been identified to be below "root"
    // Recursive process to bubble down
    if (max != i) {
        swap(arr[i], arr[max]);
        rHeapify(arr, n, max);
    }
}

/**
 *  Start building Heap from the level above the leaf nodes.
 *  This ensures that 0 operations are done to take care of
 *  the leaf nodes, and the assertion that they are the 
 *  smallest is asserted by the repeated bubbling down while
 *  the Heap is built increasingly.
 */
void buildHeap(int* arr, int len) {
    // Start from len/2 -1 to ignore all leaf nodes
    for (int i = (len/2)-1; i >= 0; i--)
        rHeapify(arr, len, i);
}

void extractMax(int* arr, int len) {
    int heapMax, i, j, n = len-1;
    heapMax = arr[0];
    arr[0] = arr[n];
    i = 0; j = 1;
    // Size of heap decreased by 1
    while (j < n) {
        if (arr[j+1] > arr[j])
            j++;
        if (arr[i] < arr[j]) { // Smaller than child node
            swap(arr[i], arr[j]);
            i = j;
            j = 2*i+1;
        }
        else
            break;
    }
    arr[n] = heapMax;
}

void heapSort(int* arr, int len) {
    int size = len;
    while (size > 1) {
        extractMax(arr, size);
        size--;
    }
}
