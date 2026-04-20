class Solution {
public:
    int maxDistance(vector<int>& colors) {
        int val = colors[0], maxi = 0;
        int n = colors.size();
        for(int i = 1; i < colors.size(); i++) {
            if(val != colors[i]) {
                maxi = i;
            }
        }
        val = colors[n-1];
        for(int i = n-2; i >= 0; i--) {
            if(val != colors[i]) {
                maxi = max(maxi, n - i - 1);
            }
        }
        return maxi;
    }
};