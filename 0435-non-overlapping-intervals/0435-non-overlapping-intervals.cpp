class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        int n = intervals.size() , i = 0 , j = 1 , count = 0;
        sort(begin(intervals),end(intervals));
        while(j<n){
            if(intervals[i][1] <= intervals[j][0]){
                i = j;
                j++;
            }else{
                if(intervals[i][1] <= intervals[j][1]){
                    j++;
                    count += 1;
                }
                else if(intervals[i][1] > intervals[j][1]){
                    i = j;
                    j++;
                    count += 1;
                }
            }
        }
        return count;
    }
};