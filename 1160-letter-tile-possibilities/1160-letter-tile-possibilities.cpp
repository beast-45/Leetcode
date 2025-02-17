class Solution {
public:
    void possibilities(string &tiles , string &currString , vector<bool> &used , unordered_set<string> &st , int n){
        st.insert(currString);
        for(int index=0 ; index<n ; index++){
            if(used[index] == true){
                continue;
            }
            used[index] = true;
            currString.push_back(tiles[index]);
            possibilities(tiles , currString , used , st , n);
            used[index] = false;
            currString.pop_back(); 
        }
    }
    int numTilePossibilities(string tiles) {
        int n = tiles.length();
        vector<bool> used(n,false);
        unordered_set<string> st;
        string currString = "";
        possibilities(tiles , currString , used , st , n);
        return st.size()-1; 
    }
};