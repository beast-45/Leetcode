class Solution {
public:
    string finalString(string s) {
        int n = s.length();
        string ans = "";
        for(int i=0 ; i<n ; i++)
        {
            if(s[i]!='i')
            {
                ans+=s[i];
            }
            else
            {
                reverse(ans.begin(),ans.end());
            }

        }
        return ans;
        
    }
};