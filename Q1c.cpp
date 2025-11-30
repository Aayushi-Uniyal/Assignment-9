#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class DSU {
public:
    vector<int> parent, rank;

    DSU(int n) {
        parent.resize(n);
        rank.resize(n, 0);
        for (int i = 0; i < n; i++) parent[i] = i;
    }

    int find(int x) {
        if (parent[x] != x)
            parent[x] = find(parent[x]);
        return parent[x];
    }

    void unite(int a, int b) {
        a = find(a);
        b = find(b);
        if (a != b) {
            if (rank[a] < rank[b]) swap(a, b);
            parent[b] = a;
            if (rank[a] == rank[b]) rank[a]++;
        }
    }
};

int main() {
    int V = 5;
    vector<pair<int, pair<int,int>>> edges;

    // (weight, (u, v))
    edges.push_back({2, {0,1}});
    edges.push_back({4, {0,2}});
    edges.push_back({1, {1,2}});
    edges.push_back({7, {1,3}});
    edges.push_back({3, {2,4}});

    sort(edges.begin(), edges.end());
    DSU dsu(V);

    cout << "Kruskal MST:\n";
    for (auto &e : edges) {
        int w = e.first;
        int u = e.second.first;
        int v = e.second.second;

        if (dsu.find(u) != dsu.find(v)) {
            cout << u << " - " << v << " (weight " << w << ")\n";
            dsu.unite(u, v);
        }
    }
    return 0;
}
