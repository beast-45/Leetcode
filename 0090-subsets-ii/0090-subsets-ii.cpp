class Solution {
public:
    void solve(int index , vector<int> &temp , vector<vector<int>> &result , vector<int> &nums){
        result.push_back(temp);
        for(int i=index ; i<nums.size() ; i++){
            if(i>index && nums[i] == nums[i-1]){
                continue;
            }
            temp.push_back(nums[i]);
            solve(i+1,temp,result,nums);
            temp.pop_back();
        }
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(begin(nums),end(nums));
        vector<int> temp;
        vector<vector<int>> result;
        solve(0,temp,result,nums);
        return result;
    }
};