class Solution {
public:
    int countMatches(vector<vector<string>>& items, string ruleKey, string ruleValue) {
        int n = items.size();
        int count = 0;
        for(int i=0 ; i<n ; i++)
        {
            vector<string> v = items[i];
            if(ruleKey == "type")
            {
                if(v[0]==ruleValue) count++;
            }
            else if(ruleKey == "color")
            {
                if(v[1]==ruleValue) count++;
            }
            else if(ruleKey == "name")
            {
                if(v[2]==ruleValue) count++;
            }
        }
        return count;
        
    }
};