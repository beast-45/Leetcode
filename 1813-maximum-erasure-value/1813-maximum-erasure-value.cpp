class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        int n = nums.size() , i = 0 , j = 0;
        int sum = 0 , maxSum = 0;
        unordered_map<int,int> mp;
        while(j<n){
            if(mp.find(nums[j]) != mp.end()){
                int nextIndex = mp[nums[j]];
                for(int k=i ; k<=nextIndex ; k++){
                    sum -= nums[k];
                    mp.erase(nums[k]);
                } 
                i = nextIndex+1;
            }
            sum += nums[j];
            mp[nums[j]] = j;
            maxSum = max(maxSum,sum);
            j++;
        }
        return maxSum;
    }
};