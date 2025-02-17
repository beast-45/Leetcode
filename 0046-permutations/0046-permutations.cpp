class Solution {
public:
    void permutations(vector<int> &nums , vector<int> &temp , vector<vector<int>> &result , unordered_set<int> &st){
        if(temp.size() == nums.size()){
            result.push_back(temp);
            return;
        }
        for(int i=0 ; i<nums.size() ; i++){
            if(st.find(nums[i]) != st.end()){
                continue;
            }
            temp.push_back(nums[i]);
            st.insert(nums[i]);
            permutations(nums , temp , result , st);
            temp.pop_back();
            st.erase(nums[i]);
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<int> temp;
        vector<vector<int>> result;
        unordered_set<int> st;
        permutations(nums , temp , result , st);
        return result;
    }
};