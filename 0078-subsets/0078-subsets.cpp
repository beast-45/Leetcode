class Solution {
public:
    void makeSubsets(int index , vector<int> &nums , vector<int> &temp , vector<vector<int>> &result){
        if(index >= nums.size()){
            result.push_back(temp);
            return;
        }
        temp.push_back(nums[index]);
        makeSubsets(index+1 , nums , temp , result);
        temp.pop_back();
        makeSubsets(index+1 , nums , temp , result);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        int n = nums.size();
        vector<int> temp;
        vector<vector<int>> result;
        makeSubsets(0 , nums , temp , result);
        return result;  
    }
};