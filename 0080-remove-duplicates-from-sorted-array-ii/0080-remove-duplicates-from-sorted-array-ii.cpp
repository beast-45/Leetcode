class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int e=0 ;
        for(int &num : nums)
        {
            if(e==0 || e==1 || nums[e-2] != num)
            {
                nums[e]=num;
                e++;
            }
        }
        return e;
        
    }
};