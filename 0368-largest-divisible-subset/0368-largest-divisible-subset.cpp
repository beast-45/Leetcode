class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        sort(begin(nums), end(nums));
        int n = nums.size();
        vector<int> t(n, 1);
        vector<int> prevIndex(n, -1);
        int maxL = 1, lastIndex = 0;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < i; j++) {
                if(nums[i] % nums[j] == 0 && t[i] < t[j] + 1) {
                    t[i] = t[j] + 1;
                    prevIndex[i] = j;
                }
            }
            if(t[i] > maxL) {
                maxL = t[i];
                lastIndex = i;
            }
        }
        vector<int> result;
        while(lastIndex >= 0) {
            result.push_back(nums[lastIndex]);
            lastIndex = prevIndex[lastIndex];
        }
        reverse(result.begin(), result.end());
        return result;
    }
};

