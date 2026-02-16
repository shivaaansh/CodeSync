class Solution {
public:
    bool check(int x, int y, int k, vector<vector<int>>& grid) {
        int target = 0;
        
        for (int j = y; j < y + k; j++) target += grid[x][j];

        // rows
        for (int i = x + 1; i < x + k; i++) {
            int rowSum = 0;
            for (int j = y; j < y + k; j++) rowSum += grid[i][j];
            if (rowSum != target) return false;
        }

        // columns
        for (int j = y; j < y + k; j++) {
            int colSum = 0;
            for (int i = x; i < x + k; i++) colSum += grid[i][j];
            if (colSum != target) return false;
        }

        // L -> R diagonal
        int diag1 = 0;
        for (int i = 0; i < k; i++) {
            diag1 += grid[x + i][y + i];
        }
        if (diag1 != target) return false;

        // R -> L diagonal
        int diag2 = 0;
        for (int i = 0; i < k; i++) {
            diag2 += grid[x + i][y + k - 1 - i];
        }
        if (diag2 != target) return false;

        return true;
    }
    bool check(int x, int y, int k, vector<vector<int>>& grid, vector<vector<int>> &rowSum, vector<vector<int>> &colSum) {
        int target = rowSum[x][y+k] - rowSum[x][y];
        for(int i = x + 1; i < x + k; i++) {
            if(rowSum[i][y+k] - rowSum[i][y] != target) return false;
        }
        for(int j = y; j < y + k; j++) {
            if(colSum[j][x+k] - colSum[j][x] != target) return false;
        }
        // L -> R diagonal
        int diag1 = 0;
        for (int i = 0; i < k; i++) {
            diag1 += grid[x + i][y + i];
        }
        if (diag1 != target) return false;

        // R -> L diagonal
        int diag2 = 0;
        for (int i = 0; i < k; i++) {
            diag2 += grid[x + i][y + k - 1 - i];
        }
        if (diag2 != target) return false;

        return true;
    }
    int largestMagicSquare(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<int>> rowSum(m, vector<int>(n+1, 0));
        vector<vector<int>> colSum(n, vector<int>(m+1, 0));
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                rowSum[i][j+1] = rowSum[i][j] + grid[i][j];
                colSum[j][i+1] = colSum[j][i] + grid[i][j];
            }
        }
        for (int k = min(m, n); k >= 2; k--) {
            for (int i = 0; i <= m - k; i++) {
                for (int j = 0; j <= n - k; j++) {
                    if (check(i, j, k, grid, rowSum, colSum)) return k;
                }
            }
        }
        return 1;
    }
};