class Solution {
public:
    const int MOD = 1e9 + 7;
    long long findPower(long long a, long long b) {
        if (b == 0) return 1;
        long long half = findPower(a, b / 2);
        long long result = (half * half) % MOD;
        if (b % 2 == 1) {
            result = (result * a) % MOD;
        }
        return result;
    }
    vector<int> getPrimes(int limit) {
        vector<bool> isPrime(limit + 1, true);
        vector<int> primes;

        for (int i = 2; i * i <= limit; i++) {
            if (isPrime[i]) {
                for (int j = i * i; j <= limit; j += i) {
                    isPrime[j] = false;
                }
            }
        }
        for (int i = 2; i <= limit; i++) {
            if (isPrime[i]) {
                primes.push_back(i);
            }
        }
        return primes;
    }
    vector<int> calculatePrimeScores(vector<int>& nums) {
        int n = nums.size();
        vector<int> primeScores(n, 0);
        int maxElement     = *max_element(nums.begin(), nums.end());
        vector<int> primes = getPrimes(maxElement);
        for (int index = 0; index < n; index++) {
            int num = nums[index];
            for (int prime : primes) {
                if (prime * prime > num)
                    break;
                if (num % prime != 0)
                    continue;
                primeScores[index]++;
                while (num % prime == 0)
                    num /= prime;
            }
            if (num > 1) {
                primeScores[index]++;
            }
        }
        return primeScores;
    }
    vector<int> findNextGreater(vector<int>& primeScores) {
        int n = primeScores.size();
        vector<int> nextGreater(n, n);
        stack<int> st;
        for (int i = n-1; i >= 0; i--) {
            while (!st.empty() && primeScores[st.top()] <= primeScores[i]) {
                st.pop();
            }
            nextGreater[i] = st.empty() ? n : st.top();
            st.push(i);
        }
        return nextGreater;
    }
    vector<int> findPrevGreater(vector<int>& primeScores) {
        int n = primeScores.size();
        vector<int> prevGreater(n, -1);
        stack<int> st;
        for (int i = 0; i < n; i++) {
            while (!st.empty() && primeScores[st.top()] < primeScores[i]) {
                st.pop();
            }
            prevGreater[i] = st.empty() ? -1 : st.top();
            st.push(i);
        }
        return prevGreater;
    }
    int maximumScore(vector<int>& nums, int k) {
        vector<int> primeScores = calculatePrimeScores(nums);
        vector<int> nextGreater = findNextGreater(primeScores);
        vector<int> prevGreater = findPrevGreater(primeScores);
        int n = nums.size();
        vector<long long> numOfSubarrays(n);
        for (int i = 0; i < n; i++) {
            numOfSubarrays[i] = (long long)(nextGreater[i] - i) * (i - prevGreater[i]);
        }
        vector<pair<int, int>> sortedArray(n);
        for (int i = 0; i < n; i++) {
            sortedArray[i] = {nums[i], i};
        }
        sort(sortedArray.begin(), sortedArray.end(), greater<>());
        long long score = 1;
        int processingIndex = 0;
        while (k > 0) {
            auto [num, index] = sortedArray[processingIndex++];
            long long operations = min((long long)k, numOfSubarrays[index]);
            score = (score * findPower(num, operations)) % MOD;
            k -= operations;
        }
        return score;
    }
};