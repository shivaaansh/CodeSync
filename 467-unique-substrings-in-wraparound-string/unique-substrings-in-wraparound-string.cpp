class Solution {
public:
    int findSubstringInWraproundString(string s) {
        vector<int> cnt(26);
        int maxi = 0;
        for(int i = 0; i < s.size(); i++) {
            if(i > 0 && ((s[i] - s[i-1] == 1) || (s[i-1] - s[i] == 25))) {
                maxi++;
            }else {
                maxi = 1;
            }
            int index = s[i] - 'a';
            cnt[index] = max(cnt[index], maxi);
        }
        int sum = 0;
        for(int i = 0; i < 26; i++) {
            sum += cnt[i];
        }
        return sum;
    }
};