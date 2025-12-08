class Solution {
public:
    int countTriples(int n) {
        int count = 0;
        for(int i=1 ; i<=n ; i++){
            for(int j=i+1 ; j<=n ; j++){
                int sum = i*i + j*j;
                int c = sqrt(sum);
                if(c <= n && c*c == sum) count += 1;
            }
        }
        return count*2;
    }
};