class Solution {
public:
    int differenceOfSums(int n, int m) {
        int divSum = 0;
        int notDivSum = 0;
        for(int i=1 ; i<=n ; i++)
        {
            i%m != 0 ? notDivSum+=i : divSum+=i;
        }
        return notDivSum - divSum;
        
    }
};