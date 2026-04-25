class Solution {
public:
    int furthestDistanceFromOrigin(string moves) {
        int n = moves.size();
        int r = 0, l = 0;
        for(char ch : moves) {
            if(ch == 'R') {
                r++;
            }else if(ch == 'L') {
                l++;
            }
        }
        int maxi = max(l, r) - min(l, r);
        
        return n - l - r + maxi;
    }
};