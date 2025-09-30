class Solution {
public:
    vector<vector<int>> result;
    void twoSum(int i , int j , int target , vector<int> &nums){
        while(i<j){
            int sum = nums[i] + nums[j];
            if(sum < target) i++;
            else if(sum > target) j--;
            else{
                while(i < j && nums[i] == nums[i+1]) i++;
                while(i < j && nums[j] == nums[j-1]) j--;
                result.push_back({-target,nums[i],nums[j]});
                i++;
                j--;
            }
        }
    }
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();
        if(n < 3) return {};
        sort(begin(nums),end(nums));
        for(int i=0 ; i<n ; i++){
            if(i > 0 && nums[i] == nums[i-1]) continue;
            int n1 = nums[i];
            int target = -n1;
            twoSum(i+1,n-1,target,nums);
        }
        return result;
    }
};