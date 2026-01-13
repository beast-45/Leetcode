class Solution {
public:
    bool check(double midY , double totalArea , vector<vector<int>> &squares){
        double bottomArea = 0.0;
        for(auto &sq : squares){
            double bottomY = sq[1] , topY = sq[1]+sq[2] , l = sq[2];
            if(midY > topY){
                bottomArea += (l*l);
            }else if(midY > bottomY){
                bottomArea += (l*(midY-bottomY));
            }
        }
        return bottomArea >= totalArea/2;
    }
    double separateSquares(vector<vector<int>>& squares) {
        double low = 0 , high = INT_MIN;
        double totalArea = 0;
        for(auto &sq : squares){
            double y = sq[1] , l = sq[2];
            totalArea += (l*l);
            high = max(high,y+l);
        }
        while(high-low > 1e-6){
            double yMid = low+(high-low)/2;
            if(check(yMid,totalArea,squares)){
                high = yMid;
            }else{
                low = yMid;
            }
        }
        return low;
    }
};