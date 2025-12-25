class Solution {
public:
    #define pp pair<int,char>
    string reorganizeString(string s) {
        priority_queue<pp> pq;
        map<char, int > mp;
        for(char c : s) mp[c]++;
        for(auto it : mp) {
            pq.push({it.second, it.first});
        }
        string ans;
        for(int i = 0; i < s.size(); i++) {
            if(pq.empty()) return "";
            auto [cnt1, c1] = pq.top();
            pq.pop();
            
            if(ans.empty() || ans.back() != c1) {
                ans.push_back(c1);
                cnt1--;
                if(cnt1 != 0)
                    pq.push({cnt1, c1});
                continue;
            }
            if(pq.empty()) return "";
            auto [cnt2, c2] = pq.top();
            pq.pop();
            
            if (ans.back() != c2) {
                ans.push_back(c2);
                cnt2--;
            }
            if(cnt1 != 0)
                pq.push({cnt1, c1});
            if(cnt2 != 0)
                pq.push({cnt2, c2});
        }
        return ans;
    }
};