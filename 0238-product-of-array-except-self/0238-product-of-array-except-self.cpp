class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int totalProduct = 1 , zeroes = 0 , n = nums.size();
        vector<int> result(n,0);
        for(int i=0 ; i<n ; i++){
            if(nums[i] == 0){
                zeroes++;
                if(zeroes > 1) return result;
            }else{
                totalProduct *= nums[i];
            }
        }
        for(int i=0 ; i<n ; i++){
            if(nums[i] == 0 && zeroes == 1) result[i] = totalProduct;
            else if(nums[i] != 0 && zeroes == 0) result[i] = totalProduct/nums[i];
            else result[i] = 0; 
        }
        return result;
    }
};
