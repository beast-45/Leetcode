class Solution {
public:
    int solve(int currNum , int num , int size , vector<int> &countDigits){
        if(size == 0){
            for(int dig=0 ; dig<=9 ; dig++){
                if(countDigits[dig] != 0 && countDigits[dig] != dig) return 0;
            }
            return currNum > num ? currNum : 0;
        }
        int result = 0;
        for(int dig=0 ; dig<=9 ; dig++){
            if(countDigits[dig] != 0 && countDigits[dig] <= size){
                countDigits[dig]--;
                result = solve(currNum*10+dig,num,size-1,countDigits);
                countDigits[dig]++;
            }
            if(result != 0) break;
        }
        return result;
    }
    int nextBeautifulNumber(int n) {
        int size = to_string(n).length();
        vector<int> countDigits(10,0);
        for(int i=0 ; i<10 ; i++) countDigits[i] = i;
        int result = solve(0,n,size,countDigits);
        if(result == 0){
            result = solve(0,n,size+1,countDigits);
        }
        return result;
    }
};