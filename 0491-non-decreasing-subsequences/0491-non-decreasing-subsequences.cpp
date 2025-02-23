class Solution {
public:
    void solve(int index , vector<int> &nums , vector<int> &temp , set<vector<int>> &result){
        if(index >= nums.size()){
            if(temp.size() >= 2){
                result.insert(temp);
            }
            return;
        }
        if(temp.empty() || nums[index] >= temp.back()){
            temp.push_back(nums[index]);
            solve(index+1 , nums , temp , result);
            temp.pop_back();
        }
        solve(index+1 , nums , temp , result);
    }
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        int n = nums.size();
        vector<int> temp;
        set<vector<int>> result;
        solve(0 , nums , temp , result);    
        return vector<vector<int>>(result.begin(),result.end());
    }
};