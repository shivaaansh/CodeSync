class Solution {
public:
    bool found = false;
    string ans;
    void rec(string &cur, int n, unordered_set<string>& st) {
        if(cur.size() == n) {
            if(st.find(cur) == st.end()) {
                ans = cur;
                found = true;
            }
            return;
        }
        for(char c : {'0', '1'}) {
            cur.push_back(c);
            rec(cur, n, st);
            if(found) return;
            cur.pop_back();
        }
    }
    string findDifferentBinaryString(vector<string>& nums) {
        int n = nums[0].size();
        unordered_set<string> st(nums.begin(), nums.end());
        string cur;
        rec(cur, n, st);
        return ans;
    }
};