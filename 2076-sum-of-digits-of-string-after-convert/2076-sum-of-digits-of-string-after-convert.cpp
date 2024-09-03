class Solution {
public:
    int getLucky(string s, int k) {
        int sum = 0 ;
        for(char &ch : s)
        {
            int val = ch - 'a' +1;
            while(val)
            {
                sum += val%10;
                val /= 10;
            }
        }
        k--;
        while(k>0)
        {
            int ans=0;
            while(sum)
            {
                int ld = sum%10;
                ans += ld;
                sum /=10;
            }
            sum = ans;
            k--;

        }
        return sum;
        
    }
};