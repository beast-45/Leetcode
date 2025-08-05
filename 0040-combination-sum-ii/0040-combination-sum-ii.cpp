class Solution {
public:
    void solve(int index , int n , int target , vector<int> &nums , vector<int> &temp , vector<vector<int>> &result){
        if(target == 0){
            result.push_back(temp);
            return;
        }
        if(index >= n || target < 0) return;
        temp.push_back(nums[index]);
        solve(index+1,n,target-nums[index],nums,temp,result);
        temp.pop_back();
        int i = index;
        while(i<n && nums[index] == nums[i]) i++;
        solve(i,n,target,nums,temp,result);
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        int n = candidates.size();
        vector<int> temp;
        vector<vector<int>> result;
        sort(begin(candidates),end(candidates));
        solve(0,n,target,candidates,temp,result);
        return result;
    }
};