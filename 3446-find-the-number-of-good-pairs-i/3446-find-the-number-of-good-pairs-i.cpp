class Solution {
public:
    int numberOfPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        int m = nums1.size();
        int n = nums2.size();
        int gpairs = 0;
        for(int i=0 ; i<m ; i++)
        {
            for(int j=0 ; j<n ; j++)
            {
                if(nums1[i]%(nums2[j]*k)==0) gpairs++;
            }
        }
        return gpairs;
        
    }
};