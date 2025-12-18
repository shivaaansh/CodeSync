class DSU {
public:
    vector<int> parent;
    DSU(int n) {
        parent.resize(n+1);
        for (int i = 1; i <= n; i++) parent[i] = i;
    }

    int find(int x) {
        if (x != parent[x])
            parent[x] = find(parent[x]);
        return parent[x];
    }

    bool unite(int u, int v) {
        int pu = find(u), pv = find(v);
        if (pu == pv) return false;
        parent[pv] = pu;
        return true;
    }
};

class Solution {
public:
    vector<int> findRedundantDirectedConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        vector<int> parent(n+1, 0);
        vector<int> edge1, edge2;
        for (auto &e : edges) {
            int u = e[0], v = e[1];
            if (parent[v] == 0) {
                parent[v] = u;
            } else {
                edge1 = {parent[v], v};
                edge2 = e;
                e[1] = 0; 
            }
        }
        DSU dsu(n);
        for (auto &e : edges) {
            if (e[1] == 0) continue;
            if (!dsu.unite(e[0], e[1])) {
                return edge1.empty() ? e : edge1;
            }
        }

        return edge2;
    }
};
