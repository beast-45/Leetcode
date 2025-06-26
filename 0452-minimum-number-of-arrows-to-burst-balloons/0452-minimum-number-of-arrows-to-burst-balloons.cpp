class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        int n = points.size();
        sort(begin(points),end(points),[&](auto &p1 , auto &p2){
            return p1[1] < p2[1];
        });
        int i = 0 , arrows = 0;
        while(i<n){
            arrows++;
            int lastArrow = points[i][1];
            while(i<n && points[i][0] <= lastArrow) i++;
        }
        return arrows;
    }
};