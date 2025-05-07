class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int n1 = s1.length();
        int n2 = s2.length();
        vector<int> f1(26,0),f2(26,0);
        for(char &ch : s1){
            f1[ch-'a']++;
        }
        int i = 0 , j = 0;
        while(j<n2){
            f2[s2[j]-'a']++;
            if(j-i+1 > n1){
                f2[s2[i]-'a']--;
                i++;
            }
            if(j-i+1 == n1 ){
                if(f1 == f2) return true;
            }
            j++;
        }
        return false;
    }
};