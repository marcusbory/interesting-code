#include <iostream>
#include <stdlib.h>
using namespace std;

// Returns index of partition
int partition(int* arr, int low, int high);
int randomPartition(int* arr, int low, int high); 
void quickSort(int* arr, int low, int high);

int main() {
    int arr[9] = { 50, 70, 80, 60, 90, 10, 20, 30, 40 };
    cout << "Original Array: ";
    for (int i = 0; i < 9; i++)
        cout << arr[i] << " ";
    cout << endl << "Sorted Array: ";
    quickSort(arr, 0, 8);
    for (int j = 0; j < 9; j++)
        cout << arr[j] << " ";
    cout << endl;
    return 0;
}

int partition(int* arr, int low, int high) {
    int key = arr[low];
    int l = low, h = high;
    while (l < h) {
        while (arr[l] <= key) { l++; }
        while (arr[h] > key) { h--; }
        if (l < h)
            swap(arr[l],arr[h]);
    }
    swap(arr[low],arr[h]);
    return h;
}

int randomPartition(int* arr, int low, int high) {
    int n = high-low;
    int random = low + rand()%n;
    swap(arr[low],arr[random]);
    int rp = partition(arr, low, high);
    // n <= 1 means only 2 or 1 element, no need repartition
    if (n > 1 && (rp < n/10.0 || rp > 9*n/10.0)) {
        random = low + rand()%n;
        swap(arr[low], arr[random]);
        rp = partition(arr, low, high);
    }
    return rp;
}

void quickSort(int* arr, int low, int high) {
    int pivot;
    if (low < high) {
        pivot = randomPartition(arr, low, high);
        quickSort(arr, low, pivot-1);
        quickSort(arr, pivot+1, high);
    }
}
