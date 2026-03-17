class Solution {
public:
    int maxRotateFunction(vector<int>& nums) {
        int n = nums.size();
        int sum = 0, f0 = 0, maxi = INT_MIN;
        for(int i = 0; i < nums.size(); i++) {
            sum += nums[i];
            f0 += i * nums[i];
        }
        vector<int> dp(n);
        dp[0] = f0;
        maxi = f0;
        for(int i = 1; i < nums.size(); i++) {
            dp[i] = dp[i-1] + sum - n * nums[n - i];
            maxi = max(maxi, dp[i]);
        } 
        return maxi;
    }
};