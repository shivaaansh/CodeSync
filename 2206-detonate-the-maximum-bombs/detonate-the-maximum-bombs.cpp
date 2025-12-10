class Solution {
public:
    int maximumDetonation(vector<vector<int>>& bombs) {
        vector<vector<int>> adj(bombs.size());
        int n = bombs.size();
        for(int i = 0; i < n; i++) {
            for(int j = i+1; j < n; j++) {
                int r1 = bombs[i][2], x1 = bombs[i][0], y1 = bombs[i][1];
                int r2 = bombs[j][2], x2 = bombs[j][0], y2 = bombs[j][1];
                long long val = 1LL * (x1 - x2) * (x1 - x2) + 1LL * (y1 - y2) * (y1 - y2);
                if(val <= 1LL * r1 * r1) {
                    adj[i].push_back(j);
                }
                if(val <= 1LL * r2 * r2) {
                    adj[j].push_back(i);
                }
            }
        }
        // find the longest starting from any point 
        int maxi = 0;
        for(int i = 0; i < bombs.size(); i++) {
            queue<int> q;
            q.push(i);
            vector<int> vis(bombs.size(), 0);
            vis[i] = 1;
            int cnt = 0;
            while(!q.empty()) {
                int top = q.front(); q.pop();
                cnt+=1;
                for(auto it : adj[top]) {
                    if(!vis[it]) {
                        vis[it] = 1;
                        q.push(it);
                    }
                }
            }
            maxi = max(maxi, cnt);
        }
        return maxi;
    }
};