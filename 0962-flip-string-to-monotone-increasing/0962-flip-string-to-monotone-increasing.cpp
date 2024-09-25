class Solution {
public:
    int n;
    int t[100001][2];
    int solve(string &s , int curr_idx , int prev )
    {
        if(curr_idx >= n) return 0;
        if(t[curr_idx][prev] != -1) return t[curr_idx][prev];
        int flip = INT_MAX;
        int noFlip = INT_MAX;

        if(s[curr_idx] == '0')
        {
            if(prev == 1)
            {
                flip = 1 + solve(s , curr_idx + 1 , 1 );
            }
            else
            {
                flip = 1 + solve(s , curr_idx + 1 , 1);
                noFlip = solve(s , curr_idx + 1 , 0);
            }
        }
        else if(s[curr_idx] == '1')
        {
            if(prev == 1)
            {
                noFlip = solve(s , curr_idx + 1 , 1);
            }
            else 
            {
                flip = 1 + solve(s , curr_idx + 1 , 0);
                noFlip = solve(s , curr_idx + 1 , 1);
            }
        }
        return t[curr_idx][prev] = min(flip , noFlip);
    }
    int minFlipsMonoIncr(string s) {
        n = s.length();
        memset(t , -1 , sizeof(t));
        return solve(s , 0 , 0 );
    }
};