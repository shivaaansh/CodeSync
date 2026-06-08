class Solution {
public:
    bool asteroidsDestroyed(int mass, vector<int>& asteroids) {
        sort(asteroids.begin(), asteroids.end());
        long long mas = mass;
        for(int as : asteroids) {
            if(mas >= as) mas += 1LL * as;
            else return false;
        }
        return true;
    }
};