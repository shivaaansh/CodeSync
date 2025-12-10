class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        if(n == 1) return {0};

        vector<vector<int>> adj(n);
        for(auto &e : edges){
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }

        // ---- Function to run BFS and return farthest node + parents ----
        auto bfs = [&](int start){
            vector<int> par(n, -1), dist(n, -1);
            queue<int> q;
            q.push(start);
            dist[start] = 0;

            int far = start;
            while(!q.empty()){
                int u = q.front(); q.pop();
                far = u;

                for(int v : adj[u]){
                    if(dist[v] == -1){
                        dist[v] = dist[u] + 1;
                        par[v] = u;
                        q.push(v);
                    }
                }
            }
            return make_pair(far, par);
        };

        // ---- Step 1: BFS from any node (0) to find X ----
        auto [X, _] = bfs(0);

        // ---- Step 2: BFS from X to find Y and parent pointers ----
        auto [Y, par] = bfs(X);

        // ---- Step 3: Recover the path X → Y (the diameter path) ----
        vector<int> path;
        int cur = Y;
        while(cur != -1){
            path.push_back(cur);
            cur = par[cur];
        }

        // ---- Step 4: Take the middle node(s) ----
        int m = path.size();
        if(m % 2 == 1) return {path[m/2]};       // odd length → 1 center
        return {path[m/2 - 1], path[m/2]};       // even → 2 centers
    }
};
