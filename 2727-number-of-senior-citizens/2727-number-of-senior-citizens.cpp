class Solution {
public:
    int countSeniors(vector<string>& details) {
        int n = details.size();
        int ans = 0;
        for(int i=0 ; i<n ; i++)
        {
            if(stoi(details[i].substr(11,2))>60) ans++;
        }
        return ans;
        
    }
};