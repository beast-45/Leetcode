class Solution {
public:
    int sumOfDigits(int n){
        int sum = 0;
        while(n>0){
            int ld = n%10;
            sum += ld;
            n /= 10;
        }
        return sum;
    }
    int maximumSum(vector<int>& nums) {
        unordered_map<int,int> mp;
        int maxSum = -1;
        for(int &num : nums){
            int digitSum = sumOfDigits(num);
            if(mp.count(digitSum)){
                maxSum = max(maxSum , num + mp[digitSum]);
                mp[digitSum] = max(num , mp[digitSum]);
            }
            else{
                mp[digitSum] = num;
            }
        }
        return maxSum;
    }
};