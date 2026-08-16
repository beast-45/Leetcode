class Solution {
public:
    bool stoneGameIX(vector<int>& stones) {
        int c0 = 0;
        int c1 = 0;
        int c2 = 0;

        for(int &stone : stones) {
            if(stone % 3 == 0) {
                c0++;
            } else if(stone % 3 == 1) {
                c1++;
            } else {
                c2++;
            }
        }

        if(c0 % 2 == 0) { //even
            return (c1 >= 1 && c2 >= 1) && (c2 >= c1 || c1 >= c2);
        }

        return abs(c1 - c2) >= 3;
    }
};