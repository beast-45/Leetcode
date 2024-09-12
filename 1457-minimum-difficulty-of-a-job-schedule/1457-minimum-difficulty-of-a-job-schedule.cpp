class Solution {
public:
    int t[301][11];
    int solve(vector<int> &jd , int n , int idx , int d)
    {
        if(d==1)
        {
            int maxD = jd[idx];
            for(int i=idx ; i<n ; i++)
            {
                maxD = max(maxD , jd[i]);
            }
            return maxD;
        }
        if(t[idx][d] != -1)
        {
            return t[idx][d];
        }

        int maxD = jd[idx];
        int finalResult = INT_MAX;

        for(int i=idx ; i<=n-d ; i++)
        {
            maxD = max(maxD , jd[i]);
            int result = maxD + solve(jd , n , i+1 , d-1);
            finalResult = min(finalResult , result);
        }
        return t[idx][d] = finalResult;
    }
    int minDifficulty(vector<int>& jd, int d) {
        int n = jd.size();
        if(n<d) return -1;
        memset(t ,-1,sizeof(t));
        return solve(jd ,n , 0 ,d);
    }
};