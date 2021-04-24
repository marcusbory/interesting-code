// Given an array with N elements, there is an element that appears strictly more than (N/2) times. Find that element.

#include <iostream>
using namespace std;

int majority(int* arr, int N);
bool checkMajority(int* arr, int maj, int N);

int main() {
    int N; cin >> N;
    int* arr = new int[N];
    for (int i = 0; i < N; ++i)
        cin >> arr[i];
    int maj = majority(arr, N);
    if (checkMajority(arr, maj, N))
        cout << "Majority element is: " << maj << endl;
    else
        cout << "No majority element." << endl;
    return 0;
}

int majority(int* arr, int N) {
    int maj = arr[0];
    int count = 1;
    for (int i = 1; i < N; ++i) {
        if (arr[i] == maj)
            ++count;
        else
            --count;
        if (count == 0) {
            maj = arr[i];
            count = 1;
        }
    }
    return maj;
}

bool checkMajority(int* arr, int maj, int N) {
    int count = 0;
    for (int i = 0; i < N; ++i) {
        if (arr[i] == maj)
            count++;
    }
    if (count <= N/2)
        return false;
    return true;
}

