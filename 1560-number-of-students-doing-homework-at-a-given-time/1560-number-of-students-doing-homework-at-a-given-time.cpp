class Solution {
public:
    int busyStudent(vector<int>& startTime, vector<int>& endTime, int queryTime) {
        int n = startTime.size();
        int nos = 0;                                         //Number of Students
        for(int i=0 ; i<n ; i++)
        {
            if(queryTime >= startTime[i]  && queryTime <= endTime[i]) nos++;
        }
        return nos;
        
    }
};