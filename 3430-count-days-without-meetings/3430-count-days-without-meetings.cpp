class Solution {
public:
    int countDays(int days, vector<vector<int>>& meetings) {
        int n = meetings.size();
        sort(begin(meetings),end(meetings));
        int freeDays = 0;
        int start = 0;
        int maxEndTime = 0;
        for(int i=0 ; i<n ; i++){
            if(meetings[i][0] > maxEndTime){
                freeDays += meetings[i][0] - maxEndTime-1;
            }
            maxEndTime = max(maxEndTime,meetings[i][1]);
        }
        if(maxEndTime < days){
            freeDays += (days-maxEndTime);
        }
        return freeDays;
    }
};