#include <iostream>
#include <vector>
using namespace std;

class Graph {
public:
    int V;
    vector<vector<int>> adj;

    Graph(int V) {
        this->V = V;
        adj.resize(V);
    }

    void addEdge(int u, int v) {
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    void DFSUtil(int u, vector<bool>& visited) {
        visited[u] = true;
        cout << u << " ";

        for (int v : adj[u]) {
            if (!visited[v])
                DFSUtil(v, visited);
        }
    }

    void DFS(int start) {
        vector<bool> visited(V, false);
        cout << "DFS: ";
        DFSUtil(start, visited);
    }
};

int main() {
    Graph g(5);
    g.addEdge(0,1);
    g.addEdge(0,2);
    g.addEdge(1,3);
    g.addEdge(2,4);

    g.DFS(0);
    return 0;
}
