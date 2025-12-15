class Solution {
public:
    int n, m;
    int MOD = 1e9 + 7;

    vector<vector<long long>> dpMax, dpMin;
    vector<vector<bool>> vis;

    pair<long long, long long> dfs(int i, int j, vector<vector<int>>& grid) {
        // Base case
        if (i == 0 && j == 0)
            return {grid[0][0], grid[0][0]};

        // If already computed
        if (vis[i][j])
            return {dpMax[i][j], dpMin[i][j]};

        long long mx = LLONG_MIN, mn = LLONG_MAX;

        // From top
        if (i > 0) {
            auto [pmx, pmn] = dfs(i - 1, j, grid);
            mx = max(mx, max(pmx * grid[i][j], pmn * grid[i][j]));
            mn = min(mn, min(pmx * grid[i][j], pmn * grid[i][j]));
        }

        // From left
        if (j > 0) {
            auto [pmx, pmn] = dfs(i, j - 1, grid);
            mx = max(mx, max(pmx * grid[i][j], pmn * grid[i][j]));
            mn = min(mn, min(pmx * grid[i][j], pmn * grid[i][j]));
        }

        vis[i][j] = true;
        dpMax[i][j] = mx;
        dpMin[i][j] = mn;

        return {mx, mn};
    }

    int maxProductPath(vector<vector<int>>& grid) {
        n = grid.size();
        m = grid[0].size();

        dpMax.assign(n, vector<long long>(m));
        dpMin.assign(n, vector<long long>(m));
        vis.assign(n, vector<bool>(m, false));

        auto res = dfs(n - 1, m - 1, grid);

        if (res.first < 0) return -1;
        return res.first % MOD;
    }
};
