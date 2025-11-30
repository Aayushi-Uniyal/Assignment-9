#include <iostream>
#include <vector>
#include <queue>
#include <climits>
using namespace std;

class Graph {
public:
    int V;
    vector<vector<pair<int,int>>> adj;

    Graph(int V) {
        this->V = V;
        adj.resize(V);
    }

    void addEdge(int u, int v, int w) {
        adj[u].push_back({v,w});
        adj[v].push_back({u,w});  // undirected
    }

    void Dijkstra(int src) {
        vector<int> dist(V, INT_MAX);
        dist[src] = 0;

        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
        pq.push({0, src});

        while (!pq.empty()) {
            int u = pq.top().second;
            int d = pq.top().first;
            pq.pop();

            if (d != dist[u]) continue;

            for (auto &p : adj[u]) {
                int v = p.first;
                int w = p.second;

                if (dist[u] + w < dist[v]) {
                    dist[v] = dist[u] + w;
                    pq.push({dist[v], v});
                }
            }
        }

        cout << "Shortest distance from source " << src << ":\n";
        for (int i = 0; i < V; i++)
            cout << i << ": " << dist[i] << endl;
    }
};

int main() {
    Graph g(5);
    g.addEdge(0,1,2);
    g.addEdge(0,2,4);
    g.addEdge(1,2,1);
    g.addEdge(1,3,7);
    g.addEdge(2,4,3);

    g.Dijkstra(0);
    return 0;
}
