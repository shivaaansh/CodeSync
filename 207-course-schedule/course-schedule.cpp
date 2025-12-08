class Solution {
public:
    bool canFinish(int num, vector<vector<int>>& pre) {
        vector<vector<int>> adj(num);
        vector<int> ind(num, 0);
        for(int i = 0; i < pre.size(); i++) {
            adj[pre[i][1]].push_back(pre[i][0]);
            ind[pre[i][0]]++;
        }
        queue<int> q;
        for(int i = 0; i < num; i++) {
            if(ind[i] == 0) {
                q.push(i);
            }
        }
        int cnt = 0;
        while(!q.empty()) {
            int top = q.front(); q.pop();
            cnt++;
            for(int it : adj[top]) {
                ind[it]--;
                if(ind[it] == 0) {
                    q.push(it);
                }
            }
        }
        return (cnt == num);
    }
};