class Solution {
public:
    bool isPossibleDivide(vector<int>& nums, int k) {
        int n = nums.size();
        if (n % k != 0) {
            return false;
        }
        map<int, int> mp;
        for (int& num : nums) {
            mp[num] += 1;
        }

        while (!mp.empty()) {
            int currentNumber = mp.begin()->first;
            for (int i = 0 ; i < k ; i++) {
                if (mp[currentNumber + i] == 0) {
                    return false;
                }
                mp[currentNumber + i]--;
                if (mp[currentNumber + i] == 0) {
                    mp.erase(currentNumber + i);
                }
            }
        }
        return true;
    }
};