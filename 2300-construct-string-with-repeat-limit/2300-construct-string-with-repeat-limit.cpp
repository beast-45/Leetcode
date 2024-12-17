class Solution {
public:
    string repeatLimitedString(string s, int repeatLimit) {
        vector<int> charCount(26, 0);
        for (char& ch : s)
        {
            charCount[ch-'a']++;
        }

        string result;
        int i = 25;

        while (i >= 0) {
            if (charCount[i] == 0)
            {
                i--;
                continue;
            }
            char ch = 'a'+i;
            int freq = min(charCount[i] , repeatLimit);
            result.append(freq , ch);
            charCount[i] -= freq;
            if(charCount[i] > 0)
            {
                int j = i-1;
                while(j >= 0  && charCount[j] == 0)
                {
                    j--;
                }
                if(j<0) break;
                result.push_back('a'+j);
                charCount[j]--;
            }

        }
        return result;
    }
};