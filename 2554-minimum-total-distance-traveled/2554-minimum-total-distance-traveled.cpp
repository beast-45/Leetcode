class Solution {
public:
    long long solve(vector<int> &robot , vector<int> &factories , int i , int j , vector<vector<long long>> &dp){
        if(i >= robot.size()){
            return 0;
        }
        if(j >= factories.size()){
            return 1e12;
        }
        if(dp[i][j] != -1){
            return dp[i][j];
        }

        long long take = abs(robot[i]-factories[j]) + solve(robot , factories , i+1 , j+1 , dp);
        long long skip = solve(robot , factories , i , j+1 , dp);

        return dp[i][j] = min(take , skip);

    }
    long long minimumTotalDistance(vector<int>& robot, vector<vector<int>>& factory) {
        sort(begin(robot),end(robot));
        vector<int> factories;
        for(auto &fac : factory){
            int facIndex = fac[0];
            int number   = fac[1];

            for(int i=0 ; i<number ; i++){
                factories.push_back(facIndex);
            }
        }
        sort(begin(factories),end(factories));
        int m = robot.size();
        int n = factories.size();
        vector<vector<long long>> dp(m+1 , vector<long long>(n+1 , -1));
        return solve(robot , factories , 0 , 0 , dp);
    }
};