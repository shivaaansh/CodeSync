class SummaryRanges {
public:
    vector<vector<int>> ans;
    SummaryRanges() {
        
    }
    
    void addNum(int value) {
        ans.push_back({value, value});
        sort(ans.begin(), ans.end());
        auto cur = ans[0];
        vector<vector<int>> temp;
        for(int i = 1; i < ans.size(); i++) {
            if(cur[1] >= ans[i][0] - 1) {
                cur[1] = max(cur[1], ans[i][1]);
            }else {
                temp.push_back(cur);
                cur = ans[i];
            }
        }
        temp.push_back(cur);
        ans = temp;
    }
    
    vector<vector<int>> getIntervals() {
        return ans;
    }
};

/**
 * Your SummaryRanges object will be instantiated and called as such:
 * SummaryRanges* obj = new SummaryRanges();
 * obj->addNum(value);
 * vector<vector<int>> param_2 = obj->getIntervals();
 */