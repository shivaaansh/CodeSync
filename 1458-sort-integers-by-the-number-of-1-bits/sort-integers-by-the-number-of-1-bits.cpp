class Solution {
public:
    static bool comp(int a, int b) {
        int cnta = __builtin_popcount(a);
        int cntb = __builtin_popcount(b);
        if(cnta == cntb) {
            return a < b;
        }
        return cnta < cntb;
    }
    vector<int> sortByBits(vector<int>& arr) {
        sort(arr.begin(), arr.end(), comp);
        return arr;      
    }
};