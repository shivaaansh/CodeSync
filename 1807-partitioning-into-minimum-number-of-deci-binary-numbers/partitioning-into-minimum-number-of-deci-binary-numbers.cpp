class Solution {
public:
    int minPartitions(string n) {
        int maxi = n.size();
        int ans = 0;
        for(int i = 0; i < maxi; i++) {
            if(ans < (n[i] - '0')) {
                ans = n[i] - '0';
            }
        }
        return ans;
    }
};