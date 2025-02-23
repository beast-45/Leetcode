class Solution {
public:
    void solve(int index , vector<int>& nums , vector<int>& temp , vector<vector<int>>& result) {
        if (temp.size() >= 2) {
            result.push_back(temp);
        }

        unordered_set<int> used;
        for (int i = index; i < nums.size(); i++) {
            if (used.count(nums[i]) == 0 && (temp.empty() || nums[i] >= temp.back())) {
                temp.push_back(nums[i]);
                used.insert(nums[i]);
                solve(i+1 , nums , temp , result);
                temp.pop_back();
            }
        }
    }
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        vector<int> temp;
        vector<vector<int>> result;
        solve(0 , nums, temp, result);
        return result;
    }
};