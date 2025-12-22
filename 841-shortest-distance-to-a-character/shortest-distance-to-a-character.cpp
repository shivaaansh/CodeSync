class Solution {
public:
    vector<int> shortestToChar(string s, char c) {
        vector<int> ans(s.size(), 1e9);
        for(int i = 0; i < s.size(); i++) {
            if(s[i] == c) {
                ans[i] = 0;
            }
        }
        int n = ans.size();
        for(int i = 0; i < n; i++) {
            if(i > 0 && ans[i] != 0) {
                ans[i] = 1 + ans[i-1];
            }
        }
        for(int i = n-1; i >= 0; i--) {
            if(i < n-1 && ans[i] != 0) {
                ans[i] = min(ans[i], 1 + ans[i+1]);
            }
        }
        return ans;
    }
};