class Solution {
public:
    vector<string> spellchecker(vector<string>& wordlist, vector<string>& queries) {
        unordered_set<string> exactMatch(begin(wordlist),end(wordlist));
        unordered_set<char> vowelSet {'a','A','e','E','i','I','o','O','u','U'};
        unordered_map<string,string> caseMap;
        unordered_map<string,string> vowelMap;
        vector<string> result;

        for(auto &word : wordlist){
            string lowerString = word;
            for(char &ch : lowerString) ch = tolower(ch);
            if(caseMap.find(lowerString) == caseMap.end()){
                caseMap[lowerString] = word;
            }
            string ignoreVowels = lowerString;
            for(char &ch : ignoreVowels){
                if(vowelSet.find(ch) != vowelSet.end()){
                    ch = '#';
                }
            }
            if(vowelMap.find(ignoreVowels) == vowelMap.end()){
                vowelMap[ignoreVowels] = word;
            } 
        }
        for(auto &queryWord : queries){
            string allSmall = queryWord , ignoreVowel = queryWord;
            for(int i=0 ; i<queryWord.size() ; i++){
                allSmall[i] = tolower(allSmall[i]);
                ignoreVowel[i] = tolower(ignoreVowel[i]);
                if(vowelSet.find(ignoreVowel[i]) != vowelSet.end()){
                    ignoreVowel[i] = '#';
                }
            }
            if(exactMatch.count(queryWord)){
                result.push_back(queryWord);
                continue;
            }
            else if(caseMap.find(allSmall) != caseMap.end()){
                result.push_back(caseMap[allSmall]);
                continue;
            }
            else if(vowelMap.find(ignoreVowel) != vowelMap.end()){
                result.push_back(vowelMap[ignoreVowel]);
            }
            else result.push_back("");
        }
        return result;
    }
};