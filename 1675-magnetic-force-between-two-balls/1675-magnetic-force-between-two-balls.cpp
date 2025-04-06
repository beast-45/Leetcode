class Solution {
public:
    bool check(int force , vector<int> &position , int balls){
        int n = position.size();
        int previousBall = position[0];
        int count = 1;
        for(int i=0 ; i<n ; i++){
            if(position[i]-previousBall >= force){
                count += 1;
                previousBall = position[i];
            }
        }
        return count >= balls;
    }
    int maxDistance(vector<int>& position, int m) {
        int n = position.size();
        sort(begin(position),end(position));
        int l = 1;
        int r = position[n-1]-position[0];
        int result = 0;
        while(l<=r){
            int mid = l + (r - l) / 2;
            if(check(mid,position,m)){
                result = mid;
                l = mid + 1;
            }
            else{
                r = mid - 1;
            }
        }
        return result;
    }
};