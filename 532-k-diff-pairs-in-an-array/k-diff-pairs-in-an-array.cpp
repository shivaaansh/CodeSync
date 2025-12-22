class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        if (k < 0) return 0;
        sort(nums.begin(), nums.end());

        int i = 0, j = 1, count = 0;

        while (j < nums.size()) {
        int diff = nums[j] - nums[i];
            if (diff == k) {
                count++;
                i++;
                j++;
                while (j < nums.size() && nums[j] == nums[j-1]) j++;
            } else if (diff < k) {
                j++;
            } else {
                i++;
                if (i == j) j++;
            }
        }
        return count;
    }

};