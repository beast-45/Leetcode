class Solution {
public:
    vector<string> sortPeople(vector<string>& names, vector<int>& heights) {
        unordered_map<int , string> m;
        int n = names.size();
        for(int i=0 ; i<n ; i++)
        {
            m[heights[i]]=names[i];
        }
        sort(begin(heights),end(heights),greater<int>());
        for(int i=0 ; i<n ; i++)
        {
            names[i]=m.at(heights[i]);
        }
        return names;

        
    }
};