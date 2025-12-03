class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_map<int,int> mp;
        int maxi = 0;
        for(int i : nums) {
            if(mp.find(i) != mp.end()) continue;
            int left = 0, right = 0;
            if(mp.find(i+1) != mp.end()) {
                right = mp[i+1];
            }
            if(mp.find(i-1) != mp.end()) {
                left = mp[i-1];
            }
            
            int len = right + left + 1;
            mp[i-left] = len;
            mp[i+right] = len;
            mp[i] = len;
            maxi = max(maxi, len);
        }
        return maxi;
    }
};