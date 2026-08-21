class Solution {
public:
    typedef long long ll;

    ll countSmaller(ll mid, vector<int>& coins) { 
        ll correctedCount = 0;
        int n = coins.size();

        //2^n * n * log(maxCoin)
        for(int expressions = 1; expressions <= (1 << n)-1; expressions++) { //2^n-1 expressions
            ll lcm = 0;
            ll order = 0; //even or odd order of expressions

            for(int i = 0; i < n; i++) {
                if(expressions & (1 << i)) {
                    order++; //we have taken ith coin

                    if(lcm == 0) {
                        lcm = coins[i];
                    } else {
                        lcm = lcm * coins[i] / gcd(lcm, coins[i]);
                    }
                }
            }

            if(order % 2 == 0) { //even then subtract
                correctedCount -= mid/lcm;
            } else {
                correctedCount += mid/lcm;
            }
        }

        return correctedCount;
    }

    ll findKthSmallest(vector<int>& coins, int k) {
        ll result = -1;

        ll l = 1;
        ll r = (ll)(*max_element(begin(coins), end(coins))) * k;

        //log(maxCoin * k) * 2^n * n * log(maxCoin)
        while(l <= r) {
            ll mid = l + (r-l)/2;

            if(countSmaller(mid, coins) >= k) { //left side me we can find kth smallest element
                result = mid;
                r = mid-1;
            } else {
                l = mid+1;
            }
        }

        return result;
    }
};