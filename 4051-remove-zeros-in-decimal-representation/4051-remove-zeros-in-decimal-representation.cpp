class Solution {
public:
    long long removeZeros(long long n) {
        string num = to_string(n);
        string newNum = "";
        for(int i=0 ; i<num.length() ; i++){
            if(num[i] != '0') newNum += num[i];
        }
        return stoll(newNum);
    }
};