class Solution {
public:
    int minDeletionSize(vector<string>& strs) {
        int n = strs[0].size();
        int m = strs.size();
        vector<int> sorted(m-1, 0);
        int cnt = 0;
        for(int i = 0; i < n; i++) {
            bool flag = false;
            for(int j = 0; j < strs.size()-1; j++) {
                if(!sorted[j] && strs[j+1][i] < strs[j][i]) {
                    flag = true;
                    break;
                }
            }
            if(flag) {
                cnt++;
                continue;
            }
            for(int j = 0; j < strs.size()-1; j++) {
                if(strs[j+1][i] > strs[j][i]) {
                    sorted[j] = true;
                }
            }  
        }
        return cnt;
    }
};