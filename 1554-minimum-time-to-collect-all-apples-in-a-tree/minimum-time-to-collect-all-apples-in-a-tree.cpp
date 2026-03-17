class Solution {
public:
    int dfs(int node, int parent, vector<vector<int>>& adj, vector<bool>& hasApple) {
        
        int totalTime = 0;
        
        for (int neighbor : adj[node]) {
            if (neighbor == parent) continue;
            int childTime = dfs(neighbor, node, adj, hasApple);
            
            if (childTime > 0 || hasApple[neighbor]) {
                totalTime += childTime + 2;
            }
        }
        
        return totalTime;
    }
    
    int minTime(int n, vector<vector<int>>& edges, vector<bool>& hasApple) {
        vector<vector<int>> adj(n);
        
        for (auto &edge : edges) {
            int u = edge[0];
            int v = edge[1];
            
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        return dfs(0, -1, adj, hasApple);
    }
};