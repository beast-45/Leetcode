class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        int n = hand.size();
        if (n % groupSize != 0) { return false; }
        map<int, int> mp;
        for (int& h : hand) {
            mp[h] += 1;
        }

        while (!mp.empty()) {
            int currentNumber = mp.begin()->first;
            for (int i = 0; i < groupSize; i++) {
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