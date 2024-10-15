class Solution {
public:
    long long minimumSteps(string s) {
        long long swaps = 0;
        int n = s.size();
        int countBlack = 0;
        for(int i=0 ; i<n ; i++)
        {
            if(s[i] == '1') countBlack += 1;
            else swaps += countBlack;
        }
        return swaps;
    }
};