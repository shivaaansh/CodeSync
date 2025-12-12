class Solution {
public:
    int n;
    unordered_map<string, int> memo;

    string encode(vector<int>& needs) {
        string s = "";
        for (int x : needs) {
            s += to_string(x) + ",";
        }
        return s;
    }
    int f(vector<int>& price, vector<vector<int>>& special, vector<int>& needs) {
        string key = encode(needs);
        if (memo.count(key)) return memo[key];
        int res = 0;
        for(int i = 0; i < n; i++) {
            res += price[i] * needs[i];
        }
        for(auto it : special) {
            bool valid = true;
            vector<int> newNeeds(needs);
            for(int i = 0; i < n; i++) {
                if(newNeeds[i] < it[i]) {
                    valid = false;
                    break;
                }
                newNeeds[i] -= it[i];
            }
            if(valid) {
                res = min(res, it[n] + f(price, special, newNeeds));
            }
        }
        return memo[key] = res;
    }
    int shoppingOffers(vector<int>& price, vector<vector<int>>& special, vector<int>& needs) {
        n = price.size();
        
        return f(price, special, needs);
        
    }
};