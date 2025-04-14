class Solution {
public:
    int matchPlayersAndTrainers(vector<int>& players, vector<int>& trainers) {
        int i = 0;
        int j = 0;
        int n1 = players.size();
        int n2 = trainers.size();
        sort(begin(players),end(players));
        sort(begin(trainers),end(trainers));
        while(i<n1 && j< n2){
            if(players[i] <= trainers[j]){
                i++;
            }
            j++;
        }
        return i;
    }
};