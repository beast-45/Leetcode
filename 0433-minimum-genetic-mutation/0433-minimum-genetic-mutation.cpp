class Solution {
public:
    int minMutation(string startGene, string endGene, vector<string>& bank) {
        vector<char> canBeUsed{'A','C','G','T'};
        unordered_set<string> bankSet(begin(bank),end(bank));
        unordered_set<string> vis;
        queue<string> q;
        
        q.push(startGene);
        vis.insert(startGene);
        int level = 0;
        while(!q.empty()){
            int n = q.size();
            while(n--){
                string currentGene = q.front();
                q.pop();
                if(currentGene == endGene){
                    return level;
                }
                for(char &ch : canBeUsed){
                    for(int i=0 ; i<currentGene.length() ; i++){
                        if(currentGene[i] == ch){
                            continue;
                        }
                        string nextGene = currentGene;
                        nextGene[i] = ch;
                        if(vis.find(nextGene) == vis.end() && bankSet.find(nextGene) != bankSet.end()){
                            vis.insert(nextGene);
                            q.push(nextGene);
                        }
                    }
                }

            }
            level += 1;
        }
        return -1;
    }
};