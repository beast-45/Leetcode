class Solution {
public:
    bool check(vector<int> &nums , vector<vector<int>> &queries , int j , int n){
        vector<int> diff(n,0);
        for(int i=0 ; i<=j ; i++){
            int start = queries[i][0];
            int end = queries[i][1];
            int sub = queries[i][2];
            diff[start] += sub;
            if(end+1 < n){
                diff[end+1] -= sub;
            } 
        }
        int cumulativeSum = 0;
        for(int i=0 ; i<n ; i++){
            cumulativeSum += diff[i];
            diff[i] = cumulativeSum;
            if(nums[i] > diff[i]){
                return false;
            }
        }
        return true;
    } 
    int minZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size();
        int q = queries.size();
        int zeroCount = count(begin(nums),end(nums),0);
        if(zeroCount == n){
            return 0;
        }
        vector<int> diff(n,0);
        int l = 0;
        int r = q-1;
        int result = -1;
        while(l<=r){
            int mid = l+(r-l)/2;
            if(check(nums , queries , mid , n)){
                result = mid+1;
                r = mid-1;
            }
            else{
                l = mid+1;
            }
        }
        return result;
    }
};