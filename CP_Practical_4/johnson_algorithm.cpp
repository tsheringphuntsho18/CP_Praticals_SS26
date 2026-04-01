#include <iostream>
#include <vector>
#include <queue>
using namespace std;

#define INF 1e9

struct Edge {
    int u, v, w;
};

bool bellmanFord(int V, vector<Edge>& edges, vector<int>& dist) {
    dist[V] = 0; // extra node

    for (int i = 0; i < V; i++) {
        for (auto e : edges) {
            if (dist[e.u] != INF && dist[e.u] + e.w < dist[e.v]) {
                dist[e.v] = dist[e.u] + e.w;
            }
        }
    }

    for (auto e : edges) {
        if (dist[e.u] + e.w < dist[e.v])
            return false;
    }

    return true;
}

vector<int> dijkstra(int V, vector<vector<pair<int,int>>>& adj, int src) {
    vector<int> dist(V, INF);
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<>> pq;

    dist[src] = 0;
    pq.push({0, src});

    while (!pq.empty()) {
        int u = pq.top().second;
        pq.pop();

        for (auto [v, w] : adj[u]) {
            if (dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
                pq.push({dist[v], v});
            }
        }
    }

    return dist;
}

void johnson(int V, vector<Edge>& edges) {
    vector<int> h(V + 1, INF);

    // Add extra node
    for (int i = 0; i < V; i++) {
        edges.push_back({V, i, 0});
    }

    if (!bellmanFord(V, edges, h)) {
        cout << "Negative cycle detected\n";
        return;
    }

    vector<vector<pair<int,int>>> adj(V);
    for (auto e : edges) {
        if (e.u != V) {
            adj[e.u].push_back({e.v, e.w + h[e.u] - h[e.v]});
        }
    }

    for (int i = 0; i < V; i++) {
        vector<int> dist = dijkstra(V, adj, i);

        cout << "From vertex " << i << ": ";
        for (int j = 0; j < V; j++) {
            if (dist[j] == INF)
                cout << "INF ";
            else
                cout << dist[j] + h[j] - h[i] << " ";
        }
        cout << endl;
    }
}

int main() {
    int V = 4;
    vector<Edge> edges = {
        {0,1,4}, {0,2,1}, {2,1,2}, {1,3,1}, {2,3,5}
    };

    johnson(V, edges);
    return 0;
}