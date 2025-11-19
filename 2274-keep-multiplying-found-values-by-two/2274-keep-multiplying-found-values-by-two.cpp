class Solution {
public:
    int findFinalValue(vector<int>& nums, int original) {
        unordered_set<int> st(begin(nums),end(nums));
        while(st.find(original) != st.end()){
            original *= 2;
        }       
        return original;
    }
};