class Solution {
public:
    bool checkBalanced(vector<int> &freq){
        int same = 0;
        for(int i=0 ; i<26 ; i++){
            if(freq[i] == 0) continue;
            if(same == 0) same = freq[i];
            else if(freq[i] != same) return false;
        }
        return true;  
    }
    int longestBalanced(string s) {
        int n = s.length() , longest = 1;
        for(int i=0 ; i<n ; i++){
            vector<int> freq(26,0);
            for(int j=i ; j<n ; j++){
                freq[s[j]-'a'] += 1;
                if(checkBalanced(freq)) longest = max(longest,j-i+1);
            }
        }
        return longest;
    }
};