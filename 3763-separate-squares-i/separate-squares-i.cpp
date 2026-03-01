class Solution {
public:
    double separateSquares(vector<vector<int>>& squares) {
        double s = 1e12, e = 0;
        double total = 0;
    
        for(auto &square : squares) {
            double y = square[1], l = square[2];
            total += l * l;
            s = min(s, y);
            e = max(e, y + l); 
        }
        double target = total / 2.0;
        for(int i = 0; i < 100; i++) {
            double m = s + (e - s) / 2;
            double cur = 0;
            for(auto &square : squares) {
                double y = square[1];
                double l = square[2];
                double h_below = max(0.0, min(l, m - y));
                cur += h_below * l;
            }
            if(cur < target) {
                s = m;
            }else {
                e = m;
            }
        }
        return e;
    }
};