class Solution {
public:
    int n;
    int t[100001][3];

    int binSearch(vector<vector<int>>&events , int endTime)
    {
        int l=0;
        int r = n-1;
        int result = n;

        while(l<=r)
        {
            int mid = l + (r - l) / 2;
            if(events[mid][0] > endTime)
            {
                result = mid;
                r = mid-1;
            }
            else{
                l = mid+1;
            }
        }
        return result;
    }

    int solve(vector<vector<int>> &events , int i , int count)
    {
        if(count == 2 || i >=n) return 0;
        if(t[i][count] != -1) return t[i][count];

        int nxtValidIndex = binSearch(events , events[i][1]);

        int take = events[i][2] + solve(events , nxtValidIndex , count+1);
        int notTake = solve(events , i+1 , count);

        return t[i][count] = max(take ,notTake);
    }

    int maxTwoEvents(vector<vector<int>>& events) {
        n = events.size();
        int count = 0; 
         
        sort(begin(events) , end(events));
        memset(t , -1 , sizeof(t));

        return solve(events , 0 , count);
    }
};