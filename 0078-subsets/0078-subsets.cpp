class Solution {
public:
    void solve(int index , vector<int> &temp , vector<vector<int>> &result , vector<int> &nums){
        result.push_back(temp);
        for(int i=index ; i<nums.size() ; i++){
            temp.push_back(nums[i]);
            solve(i+1,temp,result,nums);
            temp.pop_back();
        }
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> temp;
        vector<vector<int>> result;
        solve(0,temp,result,nums);
        return result;
    }
};