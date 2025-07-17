class Solution {
public:
    void reverse(int l , int r , vector<int> &nums){
        while(l <= r){
            int temp = nums[l];
            nums[l] = nums[r];
            nums[r] = temp;
            l++;
            r--;
        }
    }
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();
        int swapIndex = -1;
        for(int i=n-1 ; i>0 ; i--){
            if(nums[i] > nums[i-1]){
                swapIndex = i-1;
                break;
            }
        }
        if(swapIndex != -1){
            int nextIndex = swapIndex;
            for(int i=n-1 ; i>swapIndex ; i--){
                if(nums[i] > nums[swapIndex]){
                    nextIndex = i;
                    break;
                }
            }
            swap(nums[swapInde],nums[nextIndex]);
        }
        reverse(swapIndex+1,n-1,nums);
    }
};