class Solution {
public:
    bool check(int eatingSpeed , int hours , vector<int> &piles){
        int time = 0;
        for(int &pile : piles){
            if(pile % eatingSpeed == 0) time += pile/eatingSpeed;
            else time += pile/eatingSpeed+1;
        }
        return time <= hours;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int l = 1 , r = *max_element(begin(piles),end(piles));
        while(l < r){
            int mid = l+(r-l)/2;
            if(check(mid,h,piles)) r = mid;
            else l = mid+1;
        }
        return l;
    }
};