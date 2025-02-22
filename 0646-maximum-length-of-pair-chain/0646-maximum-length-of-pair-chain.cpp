class Solution {
public:
    vector<vector<int>> dp;
    int solve(int index , int prevIndex , vector<vector<int>> &pairs){
        if(index >= pairs.size()){
            return 0;
        }
        if(prevIndex != -1 && dp[index][prevIndex] != -1){
            return dp[index][prevIndex];
        }
        int take = 0;
        if(prevIndex == -1 || pairs[prevIndex][1] < pairs[index][0]){
            take = 1 + solve(index+1 , index , pairs);
        }
        int skip = solve(index+1 , prevIndex , pairs);

        int ans = max(take,skip);

        if(prevIndex != -1){
            dp[index][prevIndex] = ans;
        }

        return ans;
    }
    int findLongestChain(vector<vector<int>>& pairs) {
        int n = pairs.size();
        sort(begin(pairs),end(pairs));
        dp.resize(n,vector<int>(n,-1));
        return solve(0 , -1 , pairs); 
    }
};