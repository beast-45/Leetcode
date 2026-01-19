class Solution {
public:
    int maximizeSquareHoleArea(int n, int m, vector<int>& hBars, vector<int>& vBars) {
        sort(begin(hBars),end(hBars));
        sort(begin(vBars),end(vBars));
        int longestV = 1 , longestH = 1;
        int v = 1 , h = 1;
        for(int i=1 ; i<hBars.size() ; i++){
            if(hBars[i] == hBars[i-1]+1) h++;
            else h = 1;
            longestH = max(longestH,h);
        }
        for(int i=1 ; i<vBars.size() ; i++){
            if(vBars[i] == vBars[i-1]+1) v++;
            else v = 1;
            longestV = max(longestV,v);
        }
        int minSide = min(longestV+1,longestH+1);
        return minSide*minSide;
    }
};