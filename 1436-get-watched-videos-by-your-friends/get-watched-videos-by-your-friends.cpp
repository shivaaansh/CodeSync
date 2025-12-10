class Solution {
public:
    vector<string> watchedVideosByFriends(vector<vector<string>>& wv, vector<vector<int>>& friends, int id, int level) {
        queue<int> q;
        q.push(id);
        unordered_map<string, int> mp;
        vector<int> vis(friends.size(), 0);
        vis[id] = 1;
        while(!q.empty()) {
            int n = q.size();
            if(level == 0) {
                while(!q.empty()) {
                    int top = q.front(); q.pop();
                    for(string s : wv[top]) {
                        mp[s]++;
                    }                    
                }
                break;
            }
            while(n--) {
                int top = q.front(); q.pop();
                for(int nei : friends[top]) {
                    if(!vis[nei]) {
                        vis[nei] = 1;
                        q.push(nei);
                    }                        
                }
            }            
            level--;
        }
        vector<pair<int,string>> v;
        for(auto it : mp) {
            v.push_back({it.second, it.first});
        }
        sort(v.begin(), v.end());
        vector<string> ans;
        for(auto [_, str]: v) {
            ans.push_back(str);
        }
        return ans;
    }
};