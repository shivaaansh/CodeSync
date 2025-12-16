class Solution {
 public:
  bool checkSubarraySum(vector<int>& nums, int k) {
    int cnt = 0, sum = 0;
    unordered_map<int,int> mp;
    int n = nums.size();
    for(int i = 0; i < n; i++){
        sum += nums[i];
        // cout << sum%k << " ";
        if(sum%k == 0){
            if( i + 1 >= 2) return true;
        }
        
        if(mp.find(sum%k) != mp.end()){
            // cout << "enter " << k - sum%k << endl;
            if(i - mp[sum%k] >= 2) return true;
        }else{
            mp[sum%k] = i;
        }
        
    }   
    // cout << cnt << endl; 
    return false;
  }
};