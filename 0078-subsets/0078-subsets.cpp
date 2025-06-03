class Solution {
public:
    void solve(int index , int n , vector<int> &temp , vector<vector<int>> &result , vector<int> &nums){
        if(index == n){
            result.push_back(temp);
            return;
        }
        temp.push_back(nums[index]);
        solve(index+1,n,temp,result,nums);
        temp.pop_back();
        solve(index+1,n,temp,result,nums);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        int n = nums.size();
        vector<int> temp;
        vector<vector<int>> result;
        solve(0,n,temp,result,nums);
        return result;
    }
};