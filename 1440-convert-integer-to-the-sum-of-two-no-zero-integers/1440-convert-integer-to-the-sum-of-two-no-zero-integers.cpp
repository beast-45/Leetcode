class Solution {
public:
    bool checkForZero(int n){
        while(n>0){
            int dig = n%10;
            if(dig == 0) return false;
            n /= 10;
        }
        return true;
    }
    vector<int> getNoZeroIntegers(int n) {
        for(int i=1 ; i<n ; i++){
            if(checkForZero(i) && checkForZero(n-i)) return {i,n-i};
        }
        return {-1,-1};
    }
};