class Solution {
public:
    int trap(vector<int>& height) {
        vector<int> pref(height.size());
        pref[0] = height[0];
        vector<int> largestHeightLeft(height.size(), 0),
        largestHeightRight(height.size(), 0);

        largestHeightLeft[0] = height[0];
        for(int i = 1; i < height.size(); i++) {
            pref[i] = pref[i-1] + height[i];
            largestHeightLeft[i] = max(largestHeightLeft[i-1], height[i]);
        }

        largestHeightRight[height.size()-1] = height.back();
        for(int i = height.size()-2; i >= 0; i--) {
            largestHeightRight[i] = max(largestHeightRight[i+1], height[i]);
        }

        int total = 0;
        for(int i = 0; i < height.size(); i++) {
            int water = min(largestHeightLeft[i], largestHeightRight[i]) - height[i];
            if(water > 0) total += water;
        }

        return total;
    }
};
