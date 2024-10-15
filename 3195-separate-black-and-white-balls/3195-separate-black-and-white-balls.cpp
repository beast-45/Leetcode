class Solution {
public:
    long long minimumSteps(string s) {
        long long swaps = 0;
        int n = s.size();
        int count = 0;
        for(int i=0 ; i<n ; i++)
        {
            if(s[i] == '1') count += 1;
            if(s[i] == '0') swaps += count;
        }
        return swaps;
    }
};