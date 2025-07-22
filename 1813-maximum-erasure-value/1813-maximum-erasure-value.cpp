class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        int n = nums.size() , i = 0 , j = 0;
        int sum = 0 , maxSum = 0;
        unordered_set<int> st;
        while(j<n){
            while(st.find(nums[j]) != st.end()){
                sum -= nums[i];
                st.erase(nums[i]);
                i++;
            }
            sum += nums[j];
            st.insert(nums[j]);
            maxSum = max(maxSum,sum);
            j++;
        }
        return maxSum;
    }
};