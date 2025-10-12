class Solution {
public:
    bool scoreBalance(string s) {
        int sum = 0;
        for(char &ch : s){
            sum += (ch-'a')+1;
        }
        int currSum = 0;
        for(char &ch : s){
            currSum += (ch-'a')+1;
            if(currSum == sum-currSum) return true;
        }
        return false;
    }
};