class Solution {
public:
    bool escapeGhosts(vector<vector<int>>& ghosts, vector<int>& target) {
        int myDistance = abs(target[0]) + abs(target[1]);
        for(auto &ghost : ghosts){
            int ghostDistance = abs(target[0]-ghost[0]) + abs(target[1]-ghost[1]);
            if(ghostDistance <= myDistance){
                return false;
            }
        }
        return true;
    }
};