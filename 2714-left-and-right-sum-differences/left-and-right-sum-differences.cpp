class Solution {
public:
    vector<int> leftRightDifference(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n, 0);
        for(int i = 1; i < n; i++) {
            ans[i] += ans[i-1] + nums[i-1];
        }
        // for(int i = 0; i < n; i++) {
        //     cout << ans[i] << " ";
        // }
        int suffix = nums[n-1];
        for(int i = n-2; i >= 0; i--) {
            ans[i] = abs(ans[i] - suffix);
            suffix += nums[i];
        }
        return ans;
    }
};