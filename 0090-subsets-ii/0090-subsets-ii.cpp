class Solution {
  public:
    void solve(int index , int n , vector<int> &temp , vector<vector<int>> &result , vector<int> &nums){
        if(index >= n){
            result.push_back(temp);
            return;
        }
        temp.push_back(nums[index]);
        solve(index+1,n,temp,result,nums);
        temp.pop_back();
        int i = index+1;
        while(i<n && nums[index] == nums[i]) i++;
        solve(i,n,temp,result,nums);
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        int n = nums.size();
        sort(begin(nums),end(nums));
        vector<int> temp;
        vector<vector<int>> result;
        solve(0,n,temp,result,nums);
        return result;
    }
};