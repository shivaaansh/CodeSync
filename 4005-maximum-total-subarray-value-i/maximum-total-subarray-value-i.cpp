class Solution {
public:
    long long maxTotalValue(vector<int>& nums, int k) {
        long long ans = 1;
        int mini = *min_element(nums.begin(), nums.end());
        int maxi = *max_element(nums.begin(), nums.end());
        return 1LL * k * (maxi - mini);
    }
};