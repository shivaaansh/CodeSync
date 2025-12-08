class Solution {
public:    
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> wordSet(wordDict.begin(), wordDict.end());
        int maxLen = 0;
        for(string s : wordDict) {
            maxLen = max(maxLen, (int)s.size());
        }
        vector<int> dp(s.size()+1, 0);
        dp[0] = 1;
        // ciat
        for(int i = 0; i < s.size(); i++) {
             for(int j = max(0, i - maxLen + 1); j <= (i); j++) {
                // cout << s.substr(j, i - j + 1) << " ";
                if(wordSet.find(s.substr(j, i - j + 1)) != wordSet.end()) {
                    dp[i+1] |= dp[j];
                }
            }
            // cout << endl;
        }
        // for(int i = 0; i <= s.size(); i++) {
        //     cout << i << " " << dp[i] << endl;
        // }
        return dp[s.size()];
    }
};
