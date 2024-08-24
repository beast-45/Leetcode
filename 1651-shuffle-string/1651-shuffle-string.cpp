class Solution {
public:
    string restoreString(string s, vector<int>& indices) {
        int n = s.length();
        unordered_map<int,char> m;
        for(int i=0 ; i<n ; i++)
        {
            m[indices[i]]=s[i];
        }
        sort(indices.begin() , indices.end());
        for(int i=0 ; i<n ; i++)
        {
            s[i]=m.at(indices[i]);
        }
        return s;

        
    }
};