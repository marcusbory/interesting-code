#include <iostream>
#define INF ((int) 1e9 + 7)
#define N ((int) 1e5 + 7)
using namespace std;

struct edge {
    int from;
    int to;
    int weight;
};

int V, E;
int parent[N], min_edge[N]; // min_edge is minimum edge for vertext[i] 
edge EL[N]; // EDGE LIST EL

int findSet(int v) {
    if (parent[v] == v)
        return v;
    return parent[v] = findSet(parent[v]);
}

bool merge(int u, int v) {
    u = findSet(u); 
    v = findSet(v);
    if (u == v) 
        return false;
    parent[u] = v; // Merge
    return true;
}

void initUFDS() {
    for (int i = 0; i < N; i++)
        parent[i] = i;
}

int main() {
    freopen("boruvka-input.txt", "r", stdin);
    cin >> V >> E; cin.ignore();
    long long ans = 0;
    int count = V;
    for (int i = 0; i < E; i++) { 
        cin >> EL[i].from >> EL[i].to >> EL[i].weight;
    }
    initUFDS();
    while (count > 1) {
        for (int i = 0; i < V; i++)
            min_edge[i] = -1;

        for (int i = 0; i < E; i++) {
            if (findSet(EL[i].from) == findSet(EL[i].to))
                continue;

            int from = findSet(EL[i].from);
            if (min_edge[from] == -1 || EL[i].weight < EL[min_edge[from]].weight)
                min_edge[from] = i;

            int to = findSet(EL[i].to);
            if (min_edge[to] == -1 || EL[i].weight < EL[min_edge[to]].weight)
                min_edge[to] = i;
        }
        for (int i = 0; i < V; i++) {
            if (min_edge[i] != -1) {
                if (merge(EL[min_edge[i]].from, EL[min_edge[i]].to)) {
                    ans += EL[min_edge[i]].weight;
                    count--;
                }
            }
        }
    }
    cout << "MST weight is " << ans << endl;
    return 0;
}
