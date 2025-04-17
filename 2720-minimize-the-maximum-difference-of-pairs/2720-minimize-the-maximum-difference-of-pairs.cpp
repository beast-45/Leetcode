class Solution {
public:
    bool check(int maxD , int p , int n , vector<int> &nums){
        int i = 0;
        int countPairs = 0;
        while(i<n-1){
            if(nums[i+1] - nums[i] <= maxD){
                countPairs += 1;
                i+=2;
            }
            else{
                i+=1;
            }
        }
        return countPairs >= p;
    }
    int minimizeMax(vector<int>& nums, int p) {
        int n = nums.size();
        sort(begin(nums),end(nums));
        int l = 0;
        int r = nums[n-1]-nums[0];
        int result = 0;
        while(l <= r){
            int mid = l+(r-l)/2;
            if(bool(check(mid,p,n,nums))){
                result = mid;
                r = mid-1;
            }
            else{
                l = mid+1;
            }
        }
        return result;
    }
};