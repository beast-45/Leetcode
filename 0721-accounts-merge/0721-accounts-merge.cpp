class Solution {
public:
    vector<int> parent , rank;
    int find(int x){
        if(parent[x] == x){
            return x;
        }
        return parent[x] = find(parent[x]);
    }
    void unionf(int x , int y){
        int xp = find(x);
        int yp = find(y);
        if(xp == yp) return;
        if(rank[xp] > rank[yp]){
            parent[yp] = xp;
        }
        else if(rank[xp] < rank[yp]){
            parent[xp] = yp;
        }
        else{
            parent[xp] = yp;
            rank[yp]++;
        }
    }
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        int n = accounts.size();
        parent.resize(n);
        rank.resize(n,0);
        for(int i=0 ; i<n ; i++){
            parent[i] = i;
        }
        unordered_map<string,int> mailToParent;
        for(int i=0 ; i<n ; i++){
            for(int j=1 ; j<accounts[i].size() ; j++){
                string mail = accounts[i][j];
                if(mailToParent.find(mail) == mailToParent.end()){
                    mailToParent[mail] = i;
                }
                else{
                    unionf(i,mailToParent[mail]);
                }
            }
        }
        vector<vector<string>> mergedMails(n);
        for(auto &[mail,index] : mailToParent){
            int parentIndex = find(index);
            mergedMails[parentIndex].push_back(mail);
        }
        vector<vector<string>> mergedAccounts;
        for(int i=0 ; i<n ; i++){
            if(mergedMails[i].empty()) continue;
            sort(begin(mergedMails[i]),end(mergedMails[i]));
            vector<string> temp;
            temp.push_back(accounts[i][0]);
            temp.insert(temp.end(),begin(mergedMails[i]),end(mergedMails[i]));
            mergedAccounts.push_back(temp);
        }
        return mergedAccounts;
    }
};