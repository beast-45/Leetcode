class Solution {
public:
    int maxScoreSightseeingPair(vector<int>& values) {
        int n = values.size();
        vector<int> maxTillj(n);
        int bestPairVal = INT_MIN;

        maxTillj[0] = values[0] + 0;
        for(int i=1 ; i<n ; i++)
        {
            maxTillj[i] = max(values[i]+i , maxTillj[i-1]);
        }

        for(int j=1 ; j<n ; j++)
        {
            bestPairVal = max(bestPairVal , (values[j]-j) + maxTillj[j-1]);
        }
        return bestPairVal;
    }
};