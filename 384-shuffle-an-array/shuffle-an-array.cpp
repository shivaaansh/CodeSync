class Solution {
public:
    unordered_map<int,int> mp;
    int n;
    Solution(vector<int>& nums) {
        for(int i = 0; i < nums.size(); i++) {
            mp[nums[i]] = i;
        }
        n = nums.size();
    }
    
    vector<int> reset() {
        vector<int> ans(n);
        for(auto it : mp) {
            ans[it.second] = it.first;
        }
        return ans;
    }
    
    vector<int> shuffle() {
        vector<int> arr = reset();
        for (int i = n - 1; i > 0; --i) {
            int j = rand() % (i + 1);
            std::swap(arr[i], arr[j]);
        }
        return arr;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * vector<int> param_1 = obj->reset();
 * vector<int> param_2 = obj->shuffle();
 */