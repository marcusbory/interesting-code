#include <iostream>
#include "UFDS.hpp"
using namespace std;

struct edge {
    // Graph is undirected but just for some reference
    int from, to, weight;
};

int main() {
    // Setting up required data and data structures
    freopen("boruvka-input.txt", "r", stdin);
    int V, E;
    cin >> V >> E; cin.ignore();
    long long ans = 0;
    int count = V;
    edge* EL = new edge[E]; // Make edge list
    int* min_edge = new int[V]; // Array to store list minimum edges for each vertex
    for (int i = 0; i < E; i++)
        cin >> EL[i].from >> EL[i].to >> EL[i].weight;
    UnionFind* UFDS = new UnionFind(V);

    // MAIN BORUVKA FUNCTION
    while (count > 1) {
        // Set every vertex min neighbour edge to be -1 (unknown)
        for (int i = 0; i < V; i++)
            min_edge[i] = -1;

        for (int i = 0; i < E; i++) {
            if (UFDS->isSameSet(EL[i].from, EL[i].to))
                continue;
            
            // For this edge, check the FROM vertex
            int from = UFDS->findSet(EL[i].from);
            // If FROM vertex does not have a min edge,
            // Or if this edge's weight < previously recorded min edge for FROM vertex
            if (min_edge[from] == -1 || EL[i].weight < EL[min_edge[from]].weight)
                min_edge[from] = i;
            
            int to = UFDS->findSet(EL[i].to);
            if (min_edge[to] == -1 || EL[i].weight < EL[min_edge[to]].weight)
                min_edge[to] = i;
        }

        for (int i = 0; i < V; i++) {
            if (min_edge[i] != -1) {
                if (UFDS->unionSet(EL[min_edge[i]].from, EL[min_edge[i]].to)) {
                    ans += EL[min_edge[i]].weight;
                    count--;
                }
            }
        }
    }
    cout << "MST via Boruvka's Algo is " << ans << endl;
    delete[] EL;
    delete[] min_edge;
    delete UFDS;
    return 0;
}
