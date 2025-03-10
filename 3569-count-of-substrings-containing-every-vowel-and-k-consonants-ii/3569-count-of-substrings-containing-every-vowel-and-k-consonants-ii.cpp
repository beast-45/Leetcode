class Solution {
public:
    unordered_set<char> st = {'a', 'e', 'i', 'o', 'u'};
    bool isVowel(char x){
        return st.count(x);
    }
    long long countOfSubstrings(string word, int k) {
        int n = word.length();
        vector<int> nextConsonantIndex(n);
        int lastConsIndex = n;
        for(int i=n-1 ; i>=0 ; i--){
            nextConsonantIndex[i] = lastConsIndex;
            if(!isVowel(word[i])){
                lastConsIndex = i;
            }
        }
        unordered_map<char,int> mp;
        int i = 0; 
        int j = 0;
        int consCount = 0;
        long long count = 0;
        while(j<n){
            char ch = word[j];
            if(isVowel(ch)){
                mp[ch]+=1;
            }
            else{
                consCount += 1;
            }
            while(consCount > k){
                char ich = word[i];
                if(isVowel(ich)){
                    mp[ich] -= 1;
                    if(mp[ich] == 0){
                        mp.erase(ich);
                    }
                }
                else{
                    consCount -= 1;
                }
                i++;
            }
            while(i < n && mp.size() == 5 && consCount == k){
                int index = nextConsonantIndex[j];
                count += index-j;
                char ich = word[i];
                if(isVowel(ich)){
                    mp[ich] -= 1;
                    if(mp[ich] == 0){
                        mp.erase(ich);
                    }
                }
                else{
                    consCount -= 1;
                }
                i++;
            }
            j++;
        }
        return count;
    }
};