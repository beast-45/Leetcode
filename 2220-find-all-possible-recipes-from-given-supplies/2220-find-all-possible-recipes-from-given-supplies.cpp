class Solution {
public:
    vector<string> findAllRecipes(vector<string>& recipes, vector<vector<string>>& ingredients, vector<string>& supplies) {
        int n = recipes.size();
        unordered_set<string> reciSet(begin(recipes),end(recipes));
        unordered_set<string>supp(begin(supplies),end(supplies));
        unordered_map<string,int> indegree;
        unordered_map<string,vector<string>> adj;
        vector<string> result;

        for(int i=0 ; i<n ; i++){
            for(auto &ing : ingredients[i]){
                adj[ing].push_back(recipes[i]);     
            }
            indegree[recipes[i]] += ingredients[i].size();
        }
        queue<string> q;
        for(auto &supp : supplies){
            q.push(supp);
        }
        while(!q.empty()){
            string item = q.front();
            q.pop();
            if(reciSet.find(item)!=reciSet.end()){
                result.push_back(item);
            }
            for(auto &nextItem : adj[item]){
                indegree[nextItem]-=1;
                if(indegree[nextItem]==0){
                    q.push(nextItem);
                }
            }
        }
        return result;
    }
};