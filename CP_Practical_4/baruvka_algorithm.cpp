#include <iostream>
#include <vector>
using namespace std;

struct Edge {
    int u, v, w;
};

int find(vector<int>& parent, int i) {
    if (parent[i] != i)
        parent[i] = find(parent, parent[i]);
    return parent[i];
}

void unionSets(vector<int>& parent, vector<int>& rank, int u, int v) {
    int rootU = find(parent, u);
    int rootV = find(parent, v);

    if (rank[rootU] < rank[rootV])
        parent[rootU] = rootV;
    else if (rank[rootU] > rank[rootV])
        parent[rootV] = rootU;
    else {
        parent[rootV] = rootU;
        rank[rootU]++;
    }
}

void boruvka(int V, vector<Edge>& edges) {
    vector<int> parent(V), rank(V, 0);

    for (int i = 0; i < V; i++)
        parent[i] = i;

    int numTrees = V;
    int mstWeight = 0;

    while (numTrees > 1) {
        vector<int> cheapest(V, -1);

        for (int i = 0; i < edges.size(); i++) {
            int u = find(parent, edges[i].u);
            int v = find(parent, edges[i].v);

            if (u == v) continue;

            if (cheapest[u] == -1 || edges[i].w < edges[cheapest[u]].w)
                cheapest[u] = i;

            if (cheapest[v] == -1 || edges[i].w < edges[cheapest[v]].w)
                cheapest[v] = i;
        }

        for (int i = 0; i < V; i++) {
            if (cheapest[i] != -1) {
                Edge e = edges[cheapest[i]];
                int u = find(parent, e.u);
                int v = find(parent, e.v);

                if (u != v) {
                    mstWeight += e.w;
                    unionSets(parent, rank, u, v);
                    cout << "Edge " << e.u << "-" << e.v << " included\n";
                    numTrees--;
                }
            }
        }
    }

    cout << "Total MST weight: " << mstWeight << endl;
}

int main() {
    int V = 4;
    vector<Edge> edges = {
        {0,1,10}, {0,2,6}, {0,3,5}, {1,3,15}, {2,3,4}
    };

    boruvka(V, edges);
    return 0;
}