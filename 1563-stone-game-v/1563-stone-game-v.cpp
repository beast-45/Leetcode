class Solution {
public:
    int stoneGameV(vector<int>& stoneValue) {
        int n = stoneValue.size();

        vector<int> cumSum(n, 0);
        cumSum[0] = stoneValue[0];
        for (int i = 1; i < n; i++) {
            cumSum[i] = cumSum[i - 1] + stoneValue[i];
        }

        vector<vector<int>> t(n+1, vector<int>(n+1, 0));

        for(int l = n-1; l >= 0; l--) {
            for(int r = l+1; r < n; r++) {

                //l...r
                int score = 0;
                for(int mid = l; mid <= r-1; mid++) {
                    int leftSum  = cumSum[mid] - (l-1 >= 0 ? cumSum[l-1] : 0); //[l..mid]
                    int rightSum = cumSum[r] - cumSum[mid]; //mid+1, r

                    if(leftSum < rightSum) {
                        score = max(score, leftSum + t[l][mid]);
                    } else if(leftSum > rightSum) {
                        score = max(score, rightSum + t[mid+1][r]);
                    } else {
                        score = max({score, leftSum + t[l][mid], rightSum + t[mid+1][r]});
                    }
                }

                t[l][r] = score;
            }
        }

        return t[0][n-1];
    }
};