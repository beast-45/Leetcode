class Solution {
public:
    bool check(int speed , vector<int> &dist , double hour){
        int n = dist.size();
        double time = 0.0;
        for(int i=0 ; i<n-1 ; i++){
            double t = (double)dist[i]/(double)speed;
            time += ceil(t);
        }
        time += (double)dist[n-1]/(double)speed;
        return time <= hour;
    }
    int minSpeedOnTime(vector<int>& dist, double hour) {
        int l = 1;
        int r = 1e7;;
        int minSpeed = -1;
        while(l<=r){
            int mid = l+(r-l)/2;
            if(check(mid,dist,hour)){
                minSpeed = mid;
                r = mid-1;
            }
            else{
                l = mid+1;
            }
        }
        return minSpeed;
    }
};