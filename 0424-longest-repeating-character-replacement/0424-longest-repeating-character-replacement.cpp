class Solution {
public:
    int characterReplacement(string s, int k) {
        int i = 0 , j = 0 , n = s.length() , maxFreq = 0 , maxLen = 0;
        vector<int> freq(26,0);
        while(j<n){
            freq[s[j]-'A']++;
            maxFreq = max(maxFreq,freq[s[j]-'A']);
            int len = j-i+1;
            int conversions = len-maxFreq;
            if(conversions <= k){
                maxLen = max(maxLen,len);
            }else{
                freq[s[i]-'A']--;
                i++;
            }
            j++;
        }
        return maxLen; 
    }
};
