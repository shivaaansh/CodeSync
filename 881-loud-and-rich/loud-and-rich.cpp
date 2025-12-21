class Solution {
public:
    vector<int> loudAndRich(vector<vector<int>>& richer, vector<int>& quiet) {
        int n = quiet.size();
        vector<vector<int>> adj(n);
        vector<int> ans(n, -1), ind(n, 0);
        for(auto &it : richer) {
            adj[it[0]].push_back(it[1]);
            ind[it[1]]++;
        }
        queue<int> q;
        for(int i = 0; i < n; i++) {
            ans[i] = i;
            if(ind[i] == 0) q.push(i);
        }
        while(!q.empty()) {
            int cur = q.front();
            q.pop();
            for(int i : adj[cur]) {
                if(quiet[ans[i]] > quiet[ans[cur]]) {
                    ans[i] = ans[cur];
                }
                ind[i]--;
                if(ind[i] == 0) q.push(i);
            }
        }
        return ans;
    }
};