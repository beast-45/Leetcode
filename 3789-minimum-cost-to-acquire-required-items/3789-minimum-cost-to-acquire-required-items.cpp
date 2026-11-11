class Solution {
public:
    using ll = long long;
    long long minimumCost(int cost1, int cost2, int costBoth, int need1, int need2) {
        ll c1 = cost1 , c2 = cost2 , cb = costBoth , n1 = need1 , n2 = need2;
        if(c1+c2 < cb){
            return c1*n1 + c2*n2;
        }
        ll common = min(n1,n2);
        ll total = common * cb;
        n1 -= common;
        n2 -= common;
        if(n1 > 0){
            total += n1 * min(c1,cb);
        }else{
            total += n2 * min(c2,cb);
        }
        return total;
    }
};