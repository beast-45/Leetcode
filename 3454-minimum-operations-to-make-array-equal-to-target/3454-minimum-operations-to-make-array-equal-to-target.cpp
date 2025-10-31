class Solution {
public:
    long long minimumOperations(vector<int>& nums, vector<int>& target) {
        int n = nums.size();
        long long operations = 0;
        int prev = 0;
        for(int i=0 ; i<n ; i++){
            int curr = target[i]-nums[i];
            if((curr > 0 && prev < 0) || (curr < 0 && prev > 0)){
                operations += abs(curr);
            }
            else if(abs(curr) > abs(prev)){
                operations += abs(curr-prev);
            }
            prev = curr;
        }
        return operations;
    }
};