class Solution {
public:
    int t[366];
    int solve(vector<int> &days , vector<int> &costs , int n , int i)
    {
        if(i>=n) return 0;

        if(t[i] != -1) return t[i];

        int cost_1 = costs[0] + solve(days , costs , n , i+1);

        int j = i;
        int maxDay = days[i] + 7;
        while(j < n && days[j] < maxDay)
        {
            j++;
        }
        
        int cost_7 = costs[1] + solve(days , costs , n , j);

        j=i;
        maxDay = days[i] + 30;
        while(j < n && days[j] < maxDay)
        {
            j++;
        }

        int cost_30 = costs[2] + solve(days , costs , n , j);

        return t[i] = min({cost_1 , cost_7 , cost_30});

    }
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        int n = days.size();
        memset(t , -1 , sizeof(t));
        return solve(days , costs , n , 0);
    }
};