class Solution {
public:
    long long getCost(int mid , vector<int>& nums , vector<int>& cost){
        int n = nums.size();
        long long cosT = 0;
        for(int i=0 ; i<n ; i++){
            int operations = abs(nums[i]-mid);
            cosT += operations * (long long)cost[i];
        }
        return cosT;
    }
    long long minCost(vector<int>& nums, vector<int>& cost) {
        int l = INT_MAX;
        int h = INT_MIN;
        for(int &num : nums){
            l = min(l,num);
            h = max(h,num);
        }
        long long minCost = INT_MAX;
        while(l<=h){
            int mid = l+(h-l)/2;
            long long midCost = getCost(mid,nums,cost);
            long long midPlus1Cost = getCost(mid+1,nums,cost);
            if(midCost < midPlus1Cost){
                minCost = midCost;
                h = mid - 1;
            }
            else{
                minCost = midPlus1Cost;
                l = mid + 1;
            }
        }
        return minCost;
    }
};