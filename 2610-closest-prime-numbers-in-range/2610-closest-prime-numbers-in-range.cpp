class Solution {
public:
    vector<int> closestPrimes(int left, int right) {
        int n = right + 1;
        vector<bool> isPrime(n, true);
        isPrime[0] = isPrime[1] = false;
        for (int i=2 ; i*i<n ; i++) {
            if (isPrime[i]) {
                for (int j=i*i ; j<n ; j+=i) {
                    isPrime[j] = false;
                }
            }
        }
        vector<int> primes;
        for (int i=left ; i <= right ; i++) {
            if (isPrime[i]) {
                primes.push_back(i);
            }
        }
        vector<int> result(2, -1);
        int s = primes.size();
        if (s < 2){
            return result; 
        }
        int minDiff = INT_MAX;
        for (int i=1 ; i<s ; i++) {
            int diff = primes[i] - primes[i - 1];
            if (diff < minDiff) {
                minDiff = diff;
                result[0] = primes[i - 1];
                result[1] = primes[i];
            }
        }

        return result;
    }
};
