class Solution {
public:
    int dp[1001][1002][2];
    int f(int i, int prev, int b, vector<int>& nums) {
        if(i < 0) return 0;
        if(dp[i][prev+1][b] != -1) {
            return dp[i][prev+1][b];
        }
        int ntake = f(i-1, prev, b, nums);
        int take = 0;
        if(prev == -1)  
            take = 1 + f(i-1, i, b, nums);
        else if(nums[i] != nums[prev] && (nums[i] - nums[prev] > 0) == b) {
            take = 1 + f(i-1, i, !b, nums);
        }
        return dp[i][prev+1][b] = max(take, ntake);
    }
    int wiggleMaxLength(vector<int>& nums) {
        int n = nums.size();
        memset(dp, -1, sizeof(dp));
        
        return max(f(n-1, -1, 0, nums), f(n-1, -1, 1, nums));
    }
};