class Solution {
public:
    const int M = 1e9+7;
    int numSub(string s) {
        int n = s.length() , i = 0;
        long long streak = 0;
        long long count = 0;
        while(i<n){
            if(s[i] == '1') streak += 1;
            else{
                count += (streak*(streak+1)/2)%M;
                streak = 0;
            }
            i++;
        }
        count += (streak*(streak+1)/2)%M;
        return (int)count;
    }
};