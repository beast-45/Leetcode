class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums) {
        int n = nums.size();
        if(n==1 || n==2) return n;
        int result = 1;
        while(result<=n){
            result *= 2;
        }
        return result;
    }
};