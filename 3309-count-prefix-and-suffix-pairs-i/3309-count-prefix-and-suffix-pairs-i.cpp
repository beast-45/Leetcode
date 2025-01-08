class Solution {
public:
    bool isPreAndSuf(string &s1 , string &s2)
    {
        int n1 = s1.length();
        int n2 = s2.length();
        if(s2.substr(0 , n1) == s1 && s2.substr(n2-n1) == s1) return true;
        return false;
    }

    int countPrefixSuffixPairs(vector<string>& words) {
        int numOfPairs = 0;
        int size = words.size();

        for(int i=0 ; i<size ; i++)
        {
            for(int j=i+1 ; j<size ; j++)
            {
                numOfPairs += isPreAndSuf(words[i] , words[j]);
            }
        }
        return numOfPairs;      
    }
};