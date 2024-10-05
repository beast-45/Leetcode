class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int n = s1.length();
        string sorted = s1;
        sort(sorted.begin() , sorted.end());
        int m = s2.length();
        for(int i=0 ; i<=m-n ; i++)
        {
            string given = s2.substr(i , n);
            sort(begin(given) , end(given));
            if(given == sorted) return true;
        }
        return false;
    }
};