class Solution {
public:
    vector<bool> isArraySpecial(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size();
        int m = queries.size();

        vector<int> cumulativeSum(n,0);
        cumulativeSum[0] = 0;

        for(int i=1 ; i<n ; i++)
        {
            if(nums[i] % 2 == nums[i-1] % 2)
            {
                cumulativeSum[i] = cumulativeSum[i-1] + 1;
            }
            else
            {
                cumulativeSum[i] = cumulativeSum[i-1];
            }
        }
        vector<bool> result(m,false);
        int i = 0;
        for(vector<int> &query : queries)
        {
            int start = query[0];
            int end   = query[1];

            if(cumulativeSum[end] - cumulativeSum[start] == 0)
            {
                result[i] = true;
            }
            i++;
        }
        return result;
        
    }
};