class Solution {
public:
    int orderOfLargestPlusSign(int n, vector<vector<int>>& mines) {
        vector<vector<int>> grid(n, vector<int>(n, 1));
        
        // Mark mines
        for (auto &m : mines) {
            grid[m[0]][m[1]] = 0;
        }

        vector<vector<int>> up(n, vector<int>(n, 0)),
                            down(n, vector<int>(n, 0)),
                            left(n, vector<int>(n, 0)),
                            right(n, vector<int>(n, 0));

        // Up
        for (int j = 0; j < n; j++) {
            for (int i = 0; i < n; i++) {
                up[i][j] = grid[i][j] ? (i > 0 ? up[i-1][j] : 0) + 1 : 0;
            }
        }

        // Down
        for (int j = 0; j < n; j++) {
            for (int i = n-1; i >= 0; i--) {
                down[i][j] = grid[i][j] ? (i < n-1 ? down[i+1][j] : 0) + 1 : 0;
            }
        }

        // Left
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                left[i][j] = grid[i][j] ? (j > 0 ? left[i][j-1] : 0) + 1 : 0;
            }
        }

        // Right
        for (int i = 0; i < n; i++) {
            for (int j = n-1; j >= 0; j--) {
                right[i][j] = grid[i][j] ? (j < n-1 ? right[i][j+1] : 0) + 1 : 0;
            }
        }

        int ans = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                ans = max(ans, min({up[i][j], down[i][j], left[i][j], right[i][j]}));
            }
        }

        return ans;
    }
};
