class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int n = piles.size();
        int i = 1;
        int j = *max_element(begin(piles), end(piles));
        
        while (i < j) {
            int mid = i + (j - i) / 2;
            int hours = 0;
            for (int i=0 ; i<n ; i++) {
                if(piles[i] % mid == 0) {
                    hours += piles[i] / mid;
                }
                else {
                    hours += piles[i] / mid + 1;
                }
            }
            if(hours <= h){
                j = mid;
            }
            else{
                i = mid + 1;
            }
        }
        return i;
    }
};