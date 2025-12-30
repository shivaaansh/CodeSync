class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> pq(stones.begin(), stones.end());
        while(true) {
            if(pq.empty()) {
                return 0;
            }
            int y = pq.top(); pq.pop();
            if(pq.empty()) {
                return y;
            }
            int x = pq.top(); pq.pop();
            if(x != y) {
                pq.push(y - x);
            }
        }
        return 0;
    }
};