class Solution {
public:
    int sumIndicesWithKSetBits(vector<int>& nums, int k) {
        int n = nums.size();
        int sum = 0;
        for(int i=0 ; i<n ; i++)
        {
            int num = i;
            int c = 0;
            while(num != 0)
            {
                c += (num&1);
                num>>=1;
            }
            if(c==k) sum = sum+nums[i];
        }
        return sum;
        
    }
};