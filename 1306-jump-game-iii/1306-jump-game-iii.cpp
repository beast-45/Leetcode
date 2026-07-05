class Solution {
public:
    bool solve(int index , vector<int> &nums , unordered_set<int> &visited){
        if(index < 0 || index >= nums.size() || visited.count(index)){
            return false;
        }
        if(nums[index] == 0){
            return true;
        }
        visited.insert(index);
        return solve(index+nums[index] , nums ,visited) || solve(index-nums[index] , nums , visited);
    }
    bool canReach(vector<int>& arr, int start) {
        unordered_set<int> visited;
        return solve(start , arr , visited);
    }
};