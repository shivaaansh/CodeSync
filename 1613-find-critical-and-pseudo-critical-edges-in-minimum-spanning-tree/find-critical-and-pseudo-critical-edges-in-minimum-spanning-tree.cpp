class DSU {
public:
    vector<int> par, sz;
    int n;
    DSU(int n) {
        this->n = n;
        par.resize(n);
        sz.resize(n, 1);
        for(int i = 0; i < n; i++) par[i] = i;
    }
    int findPar(int x) {
        if(par[x] == x) return x;
        return par[x] = findPar(par[x]);
    }
    void merge(int x, int y) {
        int uparx = findPar(x);
        int upary = findPar(y);
        if(uparx == upary) return;
        if(sz[uparx] > sz[upary]) {
            par[upary] = uparx;
            sz[uparx] += sz[upary];
        } else {
            par[uparx] = upary;
            sz[upary] += sz[uparx]; 
        }
    }
};

class Solution {
public:

    int buildMST(int n, vector<vector<int>>& e, int banned, int forced, int &taken) {
        DSU d(n);
        int cost = 0;
        taken = 0;

        if(forced != -1) {
            cost += e[forced][2];
            d.merge(e[forced][0], e[forced][1]);
            taken++;
        }

        for(int i = 0; i < e.size(); i++) {
            if(i == banned) continue;
            int u = e[i][0], v = e[i][1], w = e[i][2];
            if(d.findPar(u) != d.findPar(v)) {
                d.merge(u, v);
                cost += w;
                taken++;
            }
        }

        if(taken != n - 1) return INT_MAX;
        return cost;
    }

    vector<vector<int>> findCriticalAndPseudoCriticalEdges(int n, vector<vector<int>>& edges) {
        
        for(int i = 0; i < edges.size(); i++) edges[i].push_back(i);

        // sort by weight
        sort(edges.begin(), edges.end(), [&](auto &a, auto &b){
            return a[2] < b[2];
        });

        int taken = 0;
        int baseMST = buildMST(n, edges, -1, -1, taken);

        vector<int> critical, pseudo;

        for(int i = 0; i < edges.size(); i++) {
            int ignoreTaken = 0;
            int costWithout = buildMST(n, edges, i, -1, ignoreTaken);

            if(costWithout > baseMST)
                critical.push_back(edges[i][3]);
            else {
                int forceTaken = 0;
                int costWithForce = buildMST(n, edges, -1, i, forceTaken);
                if(costWithForce == baseMST)
                    pseudo.push_back(edges[i][3]);
            }
        }

        return {critical, pseudo};
    }
};
