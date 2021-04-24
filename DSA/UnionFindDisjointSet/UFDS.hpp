// Credits: Prof Steven Halim from NUS
// Finding UFDS by rank and path compression
#pragma once
#include <iostream>
#include <vector>
using namespace std;

class UnionFind {
    private:
        vector<int> parent, rank, setSize;
        int numSets;
    public:
        UnionFind(int N);
        int findSet(int i);
        bool isSameSet(int i, int j);
        bool unionSet(int i, int j);
};

UnionFind::UnionFind(int N) {
    parent.assign(N, 0); // assigns all elements to 0
    for (int i = 0; i < N; i++)
        parent[i] = i;
    rank.assign(N, 0); // keeps track of ranks/"heights" of UFDS tree
    setSize.assign(N, 0);
    numSets = N;
}

int UnionFind::findSet(int i) {
    return (parent[i] == i) ? i : (parent[i] = findSet(parent[i]));
}

bool UnionFind::isSameSet(int i, int j) {
    return findSet(i) == findSet(j);
}

bool UnionFind::unionSet(int i, int j) {
    if (isSameSet(i, j))
        return false;
    // y acts as parent here
    int x = findSet(i), y = findSet(j);
    // Always want to append set of lower rank under bigger rank
    if (rank[x] > rank[y])
        swap(x, y);
    parent[x] = y;
    if (rank[x] == rank[y]) 
        ++rank[y];
    setSize[y] += setSize[x];
    numSets--;
    return true;
}
