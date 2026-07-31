class Solution {
public:
    int minimumPushes(string word) {
        vector<int> mp(26,0);
        for(char ch : word){
            mp[ch-'a'] += 1;
        }
        sort(begin(mp),end(mp),greater<int>());
        int result = 0;
        for(int i=0 ; i<26 ; i++){
            int freq = mp[i];
            int presses = i/8 + 1;
            result += presses*freq;
        }
        return result;
    }
};