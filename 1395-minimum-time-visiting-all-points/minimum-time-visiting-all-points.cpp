class Solution {
public:
    int minTimeToVisitAllPoints(vector<vector<int>>& points) {
        int n = points.size();
        int x = points[0][0], y = points[0][1];
        int ans = 0;
        for(int i = 1; i < n; i++) {
            int cx = points[i][0], cy = points[i][1];
            if(abs(cx - x) == abs(cy - y)) ans += abs(cx - x);
            else { int mini = min(abs(cx - x), abs(cy - y)); ans += mini + max(abs(cx - x) - mini, abs(cy - y) - mini);}
            x = cx, y = cy;
        }
        return ans;
    }
};