class Solution {
public:
    int maxCount(vector<int>& banned, int n, int maxSum) {
        unordered_set<int> st;
        for(int &ban : banned)
        {
            st.insert(ban);
        }
        int ans = 0;
        int sum = 0;

        for(int i=1 ; i<=n ; i++)
        {
            if(st.find(i) == st.end() && sum + i <= maxSum )
            {
                sum += i;
                ans += 1;
            }
        }
        return ans;
    }
};