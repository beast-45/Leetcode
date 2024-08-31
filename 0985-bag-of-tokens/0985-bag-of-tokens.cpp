class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int power) {
        int n = tokens.size();

        int score = 0;
        int maxScore = 0;

        sort(begin(tokens),end(tokens));

        int i=0; 
        int j=n-1;

        while(i<=j)
        {
            if(power >= tokens[i])
            {
                power -= tokens[i];
                score += 1;
                i++;
                maxScore = max(maxScore ,score);
            }
            else
            {
                if(score >= 1)
                {
                    power += tokens[j];
                    score -= 1;
                    j--;
                }
                else return maxScore;
            }
        }
        return maxScore;
        
    }
};