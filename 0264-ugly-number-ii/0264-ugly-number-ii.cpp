class Solution {
public:
    int nthUglyNumber(int n) {
        vector<int> arr(n+1);
        int i2;
        int i3;
        int i5;
        i2 = i3 = i5 = 1;
        
        arr[1] = 1;

        for(int i=2 ; i<=n ; i++)
        {
            int i2UglyNum = arr[i2]*2;
            int i3UglyNum = arr[i3]*3;
            int i5UglyNum = arr[i5]*5;

            int minUglyNum = min({i2UglyNum , i3UglyNum , i5UglyNum});

            arr[i] = minUglyNum;
            if(minUglyNum == i2UglyNum) i2++;
            if(minUglyNum == i3UglyNum) i3++;
            if(minUglyNum == i5UglyNum) i5++;
        }
        return arr[n];
        
    }
};