class Solution {
public:
    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {

        vector<vector<int>> adj(n);

        for(int i = 0; i < n; i++)
            if(manager[i] != -1)
                adj[manager[i]].push_back(i);

        queue<pair<int,int>> q;
        q.push({headID, 0});

        int ans = 0;
        // why this method works since there could a chance that the boss above me must have been informed as some smaller time as compared to our previous solution which calculates based on the level-wise best answer which will not give the correct answer in the last by adding the extra time.. cool.. 
        while(!q.empty()) {

            auto [node, time] = q.front();
            q.pop();

            ans = max(ans, time);

            for(int nei : adj[node])
                q.push({nei, time + informTime[node]});
        }

        return ans;
    }
};