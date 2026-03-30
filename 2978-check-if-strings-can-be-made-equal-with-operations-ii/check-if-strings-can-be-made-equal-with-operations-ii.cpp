class Solution {
public:
    bool checkStrings(string s1, string s2) {
        int n = s1.size();
        unordered_map<char,int> even, odd;
        for(int i = 0; i < n; i++) {
            if(i % 2 == 0) {
                even[s1[i]]++;
            }else {
                odd[s1[i]]++;
            }
        }
        for(int i = 0; i < n; i++) {
            if(i % 2 == 0) {
                if(even[s2[i]] == 0) return false;
                even[s2[i]]--;
                if(even[s2[i]] == 0) {
                    even.erase(s2[i]);
                }
            }else {
                if(odd[s2[i]] == 0) return false;
                odd[s2[i]]--;
                if(odd[s2[i]] == 0) {
                    odd.erase(s2[i]);
                }
            }
        }
        return (even.size() == 0 && odd.size() == 0);
    }
};