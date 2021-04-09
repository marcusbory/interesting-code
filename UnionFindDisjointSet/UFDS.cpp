#include <iostream>
#include "UFDS.hpp"
#include <vector>
using namespace std;

int main() {
    freopen("input.txt", "r", stdin);
    int N, Q;
    cin >> N >> Q; cin.ignore(); //ignores enter
    UnionFind UF(N);
    while (Q--) {
        char cmd;
        int a, b;
        cin >> cmd >> a >> b;
        if (cmd == '?') {
            if (UF.isSameSet(a, b))
                cout << "yes" << endl;
            else
                cout << "no" << endl;
        }
        else // cmd is = to union the sets
            UF.unionSet(a, b);
    }
    return 0;
}
