#include <iostream>
using namespace std;

int numberOfBST(int nodes);

int main() {
    cout << "Enter number of nodes: ";
    int nodes; cin >> nodes;
    cout << numberOfBST(nodes) << endl;
    return 0;
}

int numberOfBST(int nodes) {
    if (nodes <= 1)
        return 1;
    int count = 0;
    int ltree, rtree, root;
    // Root acts as separator
    // If root is "index" 1, left subtree has 0 nodes, right subtree has nodes-root nodes
    for (root = 1; root <= nodes; root++) {
        ltree = numberOfBST(root-1);
        rtree = numberOfBST(nodes-root);
        // count is number of combinations of ltree and rtree
        count += ltree*rtree;
    }
    return count;
}
