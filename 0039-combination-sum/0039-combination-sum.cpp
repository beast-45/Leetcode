class Solution {
public:
    void solve(int index , int target , int n ,  vector<int> &temp , vector<vector<int>> &result , vector<int> &nums){
        if(target == 0){
            result.push_back(temp);
            return;
        }
        if(index >= n || target < 0) return;
        temp.push_back(nums[index]);
        solve(index,target-nums[index],n,temp,result,nums);
        temp.pop_back();
        solve(index+1,target,n,temp,result,nums);
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        int n = candidates.size();
        vector<int> temp;
        vector<vector<int>> result;
        solve(0,target,n,temp,result,candidates);
        return result;
    }
};