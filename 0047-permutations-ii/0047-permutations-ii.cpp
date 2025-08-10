class Solution {
public:
    void solve(vector<int> &temp , vector<vector<int>> &result , vector<bool> &used , vector<int> &nums){
        if(temp.size() == nums.size()){
            result.push_back(temp);
            return;
        }
        for(int i=0 ; i<nums.size() ; i++){
            if(used[i]){
                continue;
            }
            if(i>0 && nums[i] == nums[i-1] && !used[i-1]){
                continue;
            }
            temp.push_back(nums[i]);
            used[i] = true;
            solve(temp,result,used,nums);
            temp.pop_back();
            used[i] = false;
        }
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        sort(begin(nums),end(nums));
        vector<int> temp;
        vector<bool> used(nums.size(),false);
        vector<vector<int>> result;
        solve(temp,result,used,nums);
        return result;
    }
};