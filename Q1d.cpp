#include <iostream>
#include <vector>
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
        adj[v].push_back({u,w});
    }

    void Prim() {
        vector<int> key(V, INT_MAX);
        vector<bool> inMST(V, false);

        key[0] = 0;

        cout << "Prim MST:\n";

        for (int i = 0; i < V - 1; i++) {
            int u = -1;

            for (int v = 0; v < V; v++)
                if (!inMST[v] && (u == -1 || key[v] < key[u]))
                    u = v;

            inMST[u] = true;

            for (auto &p : adj[u]) {
                int v = p.first;
                int w = p.second;

                if (!inMST[v] && w < key[v])
                    key[v] = w;
            }
        }

        for (int i = 1; i < V; i++)
            cout << "Edge weight: " << key[i] << endl;
    }
};

int main() {
    Graph g(5);
    g.addEdge(0,1,2);
    g.addEdge(0,2,4);
    g.addEdge(1,2,1);
    g.addEdge(1,3,7);
    g.addEdge(2,4,3);

    g.Prim();
    return 0;
}
