class Solution {
public:
    int minSwaps(string s) {
        int unbalanced = 0;
        for(char &ch : s)
        {
            if(ch == '[') unbalanced++;
            else if(unbalanced>0) unbalanced--;
        }
        return (unbalanced+1)/2;
    }
};