class Solution {
public:
    int threeSumMulti(vector<int>& A, int target) {
        int ans = 0, mod = 1e9+7;
        unordered_map<int, int> mp;
        for(int i = 0; i < A.size(); i++) {
            ans = (ans + mp[target-A[i]]) % mod;
            for(int j = 0; j < i; j++) mp[A[i]+A[j]]++;
        }
        return ans;
    }
};