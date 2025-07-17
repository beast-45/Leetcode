class FoodRatings {
public:
    unordered_map<string,int> foodToRatingsMap;                             // food -> Ratings
    unordered_map<string,string> foodToCuisineMap;                          // food -> cuisine
    unordered_map<string,set<pair<int,string>>> cuisineToRatingAndFoodMap;  // cuisine -> {rating,food}
    
    FoodRatings(vector<string>& foods, vector<string>& cuisines, vector<int>& ratings) {
        for(int i=0 ; i<foods.size() ; i++){
            foodToRatingsMap[foods[i]] = ratings[i];
            foodToCuisineMap[foods[i]] = cuisines[i];
            cuisineToRatingAndFoodMap[cuisines[i]].insert({-ratings[i],foods[i]});
        }
    }
    
    void changeRating(string food, int newRating) {
        string cuisine = foodToCuisineMap[food];
        int oldRating = -(foodToRatingsMap[food]);
        foodToRatingsMap[food] = newRating;
        cuisineToRatingAndFoodMap[cuisine].erase({oldRating,food});
        cuisineToRatingAndFoodMap[cuisine].insert({-newRating,food});
        
    }
    
    string highestRated(string cuisine) {
        return begin(cuisineToRatingAndFoodMap[cuisine])->second;
    }
};

/**
 * Your FoodRatings object will be instantiated and called as such:
 * FoodRatings* obj = new FoodRatings(foods, cuisines, ratings);
 * obj->changeRating(food,newRating);
 * string param_2 = obj->highestRated(cuisine);
 */