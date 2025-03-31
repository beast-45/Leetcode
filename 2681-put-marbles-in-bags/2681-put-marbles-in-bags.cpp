class Solution {
public:
    long long putMarbles(vector<int>& weights, int k) {
        int n = weights.size();
        int m = n-1;
        vector<int> pairWeights(m,0);
        for(int i=0 ; i<m ; i++){
            pairWeights[i] = weights[i] + weights[i+1];
        }
        sort(begin(pairWeights),end(pairWeights));
        long long maxScore = 0;
        long long minScore = 0;
        for(int i=0 ; i<k-1 ; i++){
            minScore += pairWeights[i];
            maxScore += pairWeights[n-2-i];
        } 
        return maxScore - minScore;
    }
};