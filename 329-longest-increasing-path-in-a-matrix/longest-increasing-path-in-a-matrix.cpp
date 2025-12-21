class Solution {
public:
    vector<vector<int>> dir;
    int n, m;
    int dp[201][201];
    int dfs(int i, int j, vector<vector<int>> &mat) {
        if(dp[i][j] != -1) return dp[i][j];
        int maxi = 1;
        for(auto it : dir) {
            int x = i + it[0], y = j + it[1];
            if(x < 0 || y < 0 || x >= n || y >= m || mat[x][y] <= mat[i][j]) continue;
            maxi = max(maxi, 1 + dfs(x, y, mat));
        }
        return dp[i][j] = maxi;
    }
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        dir = {{0,1}, {0,-1}, {-1,0}, {1,0}};
        memset(dp, -1, sizeof(dp));
        n = matrix.size(), m = matrix[0].size();
        int maxi = 0;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                maxi = max(maxi, dfs(i, j, matrix));
            }
        } 
        return maxi;
    }
};