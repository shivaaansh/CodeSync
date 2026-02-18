class Solution {
public:
    
    int maximizeSquareHoleArea(int n, int m, vector<int>& hBars, vector<int>& vBars) {
        sort(hBars.begin(), hBars.end());
        sort(vBars.begin(), vBars.end());
        int hx, hy, vx, vy;
        int res = 1, streak = 1;
        for(int i = 1; i < hBars.size(); i++) {
            if(hBars[i] - hBars[i-1] == 1) {
                streak++;
            }else {
                streak = 1;
            }
            res = max(res, streak);
        }
        res += 1;
        int ans = res;
        res = 1, streak = 1;
        for(int i = 1; i < vBars.size(); i++) {
            if(vBars[i] - vBars[i-1] == 1) {
                streak++;
            }else {
                streak = 1;
            }
            res = max(res, streak);
        }
        res += 1;
        int side = min(res, ans);
        return side * side;
    }
};