class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) {
        int n = nums.size() , l = 0 , r = 0;
        int result = 0;
        sort(begin(nums),end(nums));
        long long windowSum = 0;
        while(r<n){
            windowSum += nums[r];
            long long target = nums[r];
            while((r-l+1)*target - windowSum > k){
                windowSum -= nums[l];
                l++;
            }
            result = max(result,r-l+1);
            r++;
        }
        return result;
    }
};