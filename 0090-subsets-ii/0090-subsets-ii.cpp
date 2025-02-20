class Solution {
public:
    void solve(int index , vector<int> &nums , vector<int> &temp , vector<vector<int>> &result){
        if(index == nums.size()){
            result.push_back(temp);
            return;
        }
        temp.push_back(nums[index]);
        solve(index+1 , nums , temp , result);
        temp.pop_back();
        int idx = index+1;
        while(idx<nums.size() && nums[idx] == nums[index]){
            idx++;
        }
        solve(idx , nums , temp , result);
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(begin(nums),end(nums));
        vector<int> temp;
        vector<vector<int>> result;
        solve(0 , nums , temp , result);
        return result;
    }
};