class Solution {
public:
    vector<int> queryResults(int limit, vector<vector<int>>& queries) {
        int n = queries.size();

        vector<int> result(n);
        unordered_map<int,int> colorOfBall;
        unordered_map<int,int> mp;

        for(int i=0 ; i<n ; i++){
            int ball = queries[i][0];
            int color = queries[i][1];

            if(colorOfBall.count(ball)){
                int prevColor = colorOfBall[ball];
                mp[prevColor]--;
                if(mp[prevColor] == 0){
                    mp.erase(prevColor);
                }
            }
            colorOfBall[ball] = color;
            mp[color] += 1;

            result[i] = mp.size();
        }
        return result;
    }
};