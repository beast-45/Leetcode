class Solution {
public:
    int differenceOfSums(int n, int m) {
        int divSum = 0;
        int notdivSum = 0;
        for(int i=1 ; i<=n ; i++)
        {
            if(i%m != 0) notdivSum += i;
            else divSum += i;
        }
        return notdivSum - divSum;
        
    }
};