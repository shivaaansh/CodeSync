class FoodRatings {
public:
    unordered_map<string, string> ftc;   // food -> cuisine
    unordered_map<string, int> ftr;       // food -> rating
    unordered_map<string, set<pair<int, string>>> cts; // cuisine -> set

    FoodRatings(vector<string>& foods, vector<string>& cuisines, vector<int>& ratings) {
        for (int i = 0; i < foods.size(); i++) {
            ftc[foods[i]] = cuisines[i];
            ftr[foods[i]] = ratings[i];
            cts[cuisines[i]].insert({-ratings[i], foods[i]});
        }
    }
    
    void changeRating(string food, int newRating) {
        string cu = ftc[food];
        int oldRating = ftr[food];
        cts[cu].erase({-oldRating, food});
        cts[cu].insert({-newRating, food});
        ftr[food] = newRating;
    }
    
    string highestRated(string cuisine) {
        return cts[cuisine].begin()->second;
    }
};
