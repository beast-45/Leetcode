class Solution {
public:
    int digitSum(int num){
        int sum = 0;
        while(num>0){
            sum += num%10;
            num /= 10;
        }
        return sum;
    }
    int countLargestGroup(int n) {
        vector<int> freq(37,0);
        for(int num=1 ; num<=n ; num++){
            int sumOfDigits = digitSum(num);
            freq[sumOfDigits]++;
        }
        int largestSize = 0;
        for(int &size : freq){
            largestSize = max(largestSize,size);
        }
        int groups = count(begin(freq),end(freq),largestSize);
        return groups;
    }
};