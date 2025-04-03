class Solution {
public:
    long long maximumTripletValue(vector<int>& nums) {
        int n = nums.size();
        if(n<3){
            return 0;
        }
        vector<int> leftMaxi(n,INT_MIN) , rightMaxk(n,INT_MIN);
        for(int i=1 ; i<n ; i++){
            leftMaxi[i] = max(leftMaxi[i-1],nums[i-1]);
        }
        for(int i=n-2 ; i>=0 ; i--){
            rightMaxk[i] = max(rightMaxk[i+1],nums[i+1]);
        }
        long long result = 0;
        for(int j=1 ; j<n-1 ; j++){
            long long val = (long long)(leftMaxi[j]-nums[j])*rightMaxk[j];
            result = max(result,val);
        }
        return result;
    }
};