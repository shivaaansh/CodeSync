class Solution {
public:
    bool containsCycle(vector<vector<char>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<int>> vis(m, vector<int>(n, 0));
        vector<int> dx = {1, 0, -1, 0};
        vector<int> dy = {0, 1, 0, -1};

        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(!vis[i][j]) {
                    char ch = grid[i][j];
                    queue<pair<pair<int,int>, pair<int,int>>> q;
                    q.push({{i, j}, {-1, -1}});
                    vis[i][j] = 1;

                    while(!q.empty()) {
                        auto [curr, parent] = q.front();
                        q.pop();

                        int x = curr.first, y = curr.second;
                        int px = parent.first, py = parent.second;

                        for(int k = 0; k < 4; k++) {
                            int nx = x + dx[k];
                            int ny = y + dy[k];

                            if(nx >= 0 && ny >= 0 && nx < m && ny < n 
                               && grid[nx][ny] == ch) {

                                if(!vis[nx][ny]) {
                                    vis[nx][ny] = 1;
                                    q.push({{nx, ny}, {x, y}});
                                } 
                                else if(nx != px || ny != py) {
                                    return true;
                                }
                            }
                        }
                    }
                }
            }
        }
        return false;
    }
};