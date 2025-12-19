class Solution {
public:
    #define ll long long 
    int numberOfSets(int n, int maxDistance, vector<vector<int>>& roads) {
        int ans = 0;
        ll INF = 1e18;
        for(int m = 0; m < (1 << n); m++) {
            vector<vector<ll>> dist(n, vector<ll> (n, INF));
            vector<int> nodes;
            for(int i = 0; i < n; i++) {
                dist[i][i] = 0;
                if((m & (1 << i)))
                    nodes.push_back(i);
            }
            if(nodes.size() <= 1) {
                ans++;
                continue;
            }
            for(auto &r : roads) {
                int u = r[0], v = r[1], w = r[2];
                if((m & (1 << u)) && (m & (1 << v))) {
                    dist[u][v] = min(dist[u][v],(ll) w);
                    dist[v][u] = min(dist[v][u],(ll) w);
                }
            }
            for(int k : nodes) {
                for(int i : nodes) {
                    for(int j : nodes) {
                        dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
                    }
                }
            }

            int ok = 1;
            for(int i : nodes) {
                for(int j : nodes) {
                    if(maxDistance < dist[i][j]) {
                        ok = 0;
                        break;
                    }
                }
                if(!ok) {
                    break;
                }
            }
            if(ok) ans += 1;
        }
        return ans;
    }
};