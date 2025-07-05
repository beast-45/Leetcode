class Solution {
public:
    void twoSum(int l , int r , int n1 , vector<int> &nums , int &result , int target){
        while(l < r){
            int sum = n1 + nums[l] + nums[r];
            int diff = abs(target - sum);
            if(diff < abs(result-target)){
                result = sum;
            }
            if(sum < target){
                l++;
            }else{
                r--;
            }
        }
    }
    int threeSumClosest(vector<int>& nums, int target) {
        int n = nums.size();
        int result = accumulate(begin(nums),begin(nums)+3,0);
        sort(begin(nums),end(nums));
        for(int i=0 ; i<n ; i++){
            int n1 = nums[i];
            twoSum(i+1,n-1,n1,nums,result,target);
        }
        return result;
    }
};