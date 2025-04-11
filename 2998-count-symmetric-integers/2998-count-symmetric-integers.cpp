class Solution {
public:
    bool check(string &s){
        int n = s.length();
        int firstHalfSum = 0 , secondHalfSum = 0;
        for(int i=0 ; i<n/2 ; i++){
            firstHalfSum += s[i] - '0';
        }
        for(int i=n/2 ; i<n ; i++){
            secondHalfSum += s[i] - '0';
        }
        return firstHalfSum == secondHalfSum;
    }
    int countSymmetricIntegers(int low, int high) {
        int count = 0;
        for(int i=low ; i<=high ; i++){
            string s = to_string(i);
            if(s.length()%2 == 0 && check(s)){
                count += 1;
            }
        }
        return count;
    }
};