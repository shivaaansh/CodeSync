class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        int cntl = 0; int n = nums.size();
        vector<int> ans(n, pivot);
        int front = 0, back = n-1;
        for(int i = 0; i < n; i++) {
            if(nums[i] < pivot) {
                ans[front++] = nums[i];
            }else if (nums[i] == pivot) {
                cntl++;
            }
        }
        front += cntl;
        for(int i = 0; i < n; i++) {
            if(nums[i] > pivot) {
                ans[front++] = nums[i];
            }
        }
        return ans;
    }
};