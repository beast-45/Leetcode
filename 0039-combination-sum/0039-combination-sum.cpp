class Solution {
public:
    void solve(int index , int sum , vector<int> &temp , vector<vector<int>> &result , vector<int> &nums , int target){
        if(sum == target){
            result.push_back(temp);
            return;
        }
        if(index >= nums.size() || sum > target){
            return;
        }
        temp.push_back(nums[index]);
        solve(index,sum+nums[index],temp,result,nums,target);
        temp.pop_back();
        solve(index+1,sum,temp,result,nums,target);
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> temp;
        vector<vector<int>> result;
        sort(begin(candidates),end(candidates));
        solve(0,0,temp,result,candidates,target);
        return result;
    }
};