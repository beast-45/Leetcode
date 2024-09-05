class Solution {
public:
    vector<int> missingRolls(vector<int>& rolls, int mean, int n) {
        int m = rolls.size();
        int sumM = 0;
        for(int &roll : rolls)
        {
            sumM += roll;
        }
        int sumN = mean*(m+n) - sumM;
        if(sumN > n*6 || sumN < n) return {};
        vector<int> missingObs(n , sumN/n);
        sumN %= n;

        for(int i=0 ; i<sumN ; i++)
        {
            missingObs[i]++;
        }
        return missingObs;   
    }
};