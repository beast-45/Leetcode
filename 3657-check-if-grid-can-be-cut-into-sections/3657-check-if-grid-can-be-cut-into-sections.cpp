class Solution {
public:
    void merge(vector<vector<int>> &intervals , vector<vector<int>> &result){
        int n = intervals.size();
        sort(begin(intervals),end(intervals));
        for(int i=0 ; i<n ; i++){
            if(!result.empty() && intervals[i][0] < result.back()[1]){
                result.back()[1] = max(intervals[i][1],result.back()[1]);
            }
            else{
                result.push_back(intervals[i]);
            }
        }
    }
    bool checkValidCuts(int n, vector<vector<int>>& rectangles) {
        vector<vector<int>> xIntervals;
        vector<vector<int>> yIntervals;
        vector<vector<int>> mergeX;
        vector<vector<int>> mergeY;
        for(auto &rectangle : rectangles){
            vector<int> xi = {rectangle[0],rectangle[2]};
            vector<int> yi = {rectangle[1],rectangle[3]};
            xIntervals.push_back(xi);
            yIntervals.push_back(yi);
        }
        merge(xIntervals,mergeX);
        merge(yIntervals,mergeY);
        return mergeX.size() > 2 || mergeY.size() > 2;
    }
};