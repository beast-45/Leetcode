class Solution {
public:
    vector<int> decompressRLElist(vector<int>& nums) {
        vector<int> arr;
        int n = nums.size();
        for(int i=0 ; i<n ; i+=2)
        {
            while(nums[i] != 0)
            {
                arr.push_back(nums[i+1]);
                nums[i]--;
            }
        }
        return arr;
        
    }
};