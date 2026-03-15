class Solution {
public:
    vector<int> pathInZigZagTree(int label) {
        int level = 0;
        while(pow(2, level) <= label) level++;
        vector<int> ans(level);
        for(; label >= 1; label /= 2, --level) {
            ans[level - 1] = label;
            label = pow(2, level) - 1 - label + pow(2, level - 1);
        }
        return ans;
    }
};