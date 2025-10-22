class Solution {
public:
    int maxFrequency(vector<int>& nums, int k, int numOperations) {
        int n = nums.size() , result = 1;
        int maxEl = *max_element(begin(nums),end(nums));
        unordered_map<int,int> freqMap;
        vector<int> diff(maxEl+2,0);
        for(int i=0 ; i<n ; i++){
            freqMap[nums[i]]++;
            int l = max(0,nums[i]-k);
            int r = min(maxEl,nums[i]+k);
            diff[l]++;
            diff[r+1]--;
        }
        for(int target=0 ; target<maxEl+1 ; target++){
            diff[target] += (target == 0) ? 0 : diff[target-1];
            int targetFreq = freqMap[target];
            int operations = diff[target]-targetFreq;
            int maxOperationsAllowed = min(operations,numOperations);
            result = max(result,targetFreq+maxOperationsAllowed);
        }
        return result;
    }
};