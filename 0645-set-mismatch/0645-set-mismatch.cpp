class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        int n = nums.size();
        int dup = -1;
        int miss = -1;
        for(int i=0 ; i<n ; i++)
        {
            if(nums[abs(nums[i])-1] < 0)
            {
                dup = abs(nums[i]);
            }
            else nums[abs(nums[i])-1] *= (-1);
        }
        for(int i=0 ; i<n ; i++)
        {
            if(nums[i]>0)
            {
                miss = i+1;
            }
        }
        return {dup,miss};
        
    }
};