class Solution {
public:
    long long calculateScore(vector<string>& instructions, vector<int>& values) {
        int n = values.size();
        vector<int> vis(n,false);
        int i = 0;
        long long score = 0;
        while(i>=0 && i<n){
            if(vis[i]){
                break;
            }
            vis[i] = true;
            if(instructions[i] == "add"){
                score += values[i];
                i += 1;
            }
            else if(instructions[i] == "jump"){
                i += values[i];
            }
        }
        return score;
    }
};