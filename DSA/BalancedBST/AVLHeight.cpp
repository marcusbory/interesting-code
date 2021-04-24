#include <iostream>
using namespace std;

int minNodes(int height);

int main() {
    cout << "NOTE: Height begins from 0 (NUS Standard). -1 Height implies empty tre (trivial)." << endl;
    cout << "Enter height of AVL Tree: ";
    int height;
    cin >> height;
    cout << "Minimum number of nodes required: " << minNodes(height) << endl;
}

int minNodes(int height) {
    if (height < 0) return 0;
    if (height == 0) return 1;
    if (height == 1) return 2;
    return minNodes(height-1) + minNodes(height-2) + 1;
}
