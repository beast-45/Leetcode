class Solution {
public:
    bool check(string s , int num , int idx , int currSum){
        if(idx == s.length()){
            return currSum == num;
        }
        if(currSum > num){
            return false;
        }
        bool equal = false;
        for(int j=idx ; j<s.length() ; j++){
            string subStr = s.substr(idx , j-idx+1);
            int value = stoi(subStr);
            equal = equal || check(s , num , j+1 , currSum + value);
            if(equal == true){
                return true;
            }
        }
        return equal;
    }
    int punishmentNumber(int n) {
        int punishment = 0;
        for(int num=0 ; num<=n ; num++){
            int sq = num*num;
            string s = to_string(sq);
            if(check(s , num , 0 , 0)){
                punishment += sq;
            }
        }
        return punishment;
    }
};