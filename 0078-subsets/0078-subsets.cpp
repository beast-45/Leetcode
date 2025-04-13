class Solution {
public:
    void solve(int index , vector<int> &temp , vector<vector<int>> &result , vector<int> &nums){
        if(index >= nums.size()){
            result.push_back(temp);
            return;
        }
        temp.push_back(nums[index]);
        solve(index+1,temp,result,nums);
        temp.pop_back();
        solve(index+1,temp,result,nums);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> temp;
        vector<vector<int>> result;
        solve(0,temp,result,nums);
        return result;
    }
};