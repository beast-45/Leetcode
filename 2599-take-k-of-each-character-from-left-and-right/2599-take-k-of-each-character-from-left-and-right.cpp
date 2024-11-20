class Solution {
public:
    int takeCharacters(string s, int k) {
        int n = s.size();

        int countA = 0;
        int countB = 0;
        int countC = 0;

        int notdelws = 0;  
        for(char &ch : s)
        {
            if(ch == 'a') countA++;
            else if(ch == 'b') countB++;
            else countC++;
        }

        if(countA < k || countB < k || countC < k) return -1;

        int i = 0;
        int j = 0;

        while(j < n)
        {
            if(s[j] == 'a') countA--;
            if(s[j] == 'b') countB--;
            if(s[j] == 'c') countC--;

            while(i <= j && (countA < k || countB < k || countC < k))
            {
                if(s[i] == 'a') countA++;
                else if(s[i] == 'b') countB++;
                else countC++;
                i++;
            } 
            notdelws = max(notdelws , j-i+1);
            j++;
        }
        return n - notdelws;
    }
};