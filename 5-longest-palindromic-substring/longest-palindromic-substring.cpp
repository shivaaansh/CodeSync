class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size();
        vector<vector<int>> ispal(n, vector<int>(n, 0));
        int maxi = 1;
        string t = s.substr(0, 1);
        for(int i = 0; i < n; i++) {
            for(int j = 0; j <= i; j++) {
                 if(s[i] == s[j] && ((i-j <= 2) || (ispal[i-1][j+1]))) {
                    ispal[i][j] = 1;
                    if(maxi < (i - j + 1)) {
                        maxi = (i - j + 1);
                        t = s.substr(j, (i - j + 1));
                    }
                }
            }
        }
        return t;
    }
};