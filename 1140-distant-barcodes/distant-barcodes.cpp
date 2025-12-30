class Solution {
public:
    vector<int> rearrangeBarcodes(vector<int>& barcodes) {
        int i = 0;
        map<int,int> mp;
        priority_queue<pair<int,int>> pq;
        int n = barcodes.size();
        for(int it : barcodes) {
            mp[it]++;
        }
        for(auto it : mp) {
            pq.push({it.second, it.first});
        }
        
        vector<int> ans(n, 0);
        int cnt = 0, ele;
        for(int i = 0; i < n; i+=2) {
            if(cnt == 0){
                auto it = pq.top();
                cnt = it.first, ele = it.second;
                pq.pop();
            }
            ans[i] = ele;
            cnt--;
        }
        for(int i = 1; i < n; i+=2) {
            if(cnt == 0){
                auto it = pq.top();
                cnt = it.first, ele = it.second;
                pq.pop();
            }
            ans[i] = ele;
            cnt--;
        }
        return ans;
    }
};