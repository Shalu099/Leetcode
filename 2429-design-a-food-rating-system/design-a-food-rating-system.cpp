class FoodRatings {
    struct cmp {
        bool operator()(const pair<int,string>& a, const pair<int,string>& b) const {
            if (a.first != b.first) 
                return a.first > b.first; // higher rating first
            return a.second < b.second;   // lexicographically smaller first
        }
    };

    unordered_map<string, pair<string,int>> foodInfo; // food -> {cuisine, rating}
    unordered_map<string, set<pair<int,string>, cmp>> cuisineFoods; // cuisine -> set of {rating, food}

public:
    FoodRatings(vector<string>& foods, vector<string>& cuisines, vector<int>& ratings) {
        for (int i = 0; i < foods.size(); i++) {
            string food = foods[i];
            string cuisine = cuisines[i];
            int rating = ratings[i];
            foodInfo[food] = {cuisine, rating};
            cuisineFoods[cuisine].insert({rating, food});
        }
    }
    
    void changeRating(string food, int newRating) {
        auto [cuisine, oldRating] = foodInfo[food];
        // Remove old entry
        cuisineFoods[cuisine].erase({oldRating, food});
        // Insert new entry
        cuisineFoods[cuisine].insert({newRating, food});
        // Update foodInfo
        foodInfo[food] = {cuisine, newRating};
    }
    
    string highestRated(string cuisine) {
        return cuisineFoods[cuisine].begin()->second; // first element has highest rating
    }
};
