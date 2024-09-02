class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string, int> mp;
        vector<pair<string, int>> vp;
        vector<string> topK;

        for (string s : words) {
            mp[s]++;
        }

        for (auto &it : mp) {
            vp.push_back({it.first, it.second});
        }

        auto lambda = [&](pair<string, int>& p1, pair<string, int>& p2) {
            if (p1.second == p2.second)
                return p1.first < p2.first;
            else
                return p1.second > p2.second;
        };

        sort(begin(vp), end(vp), lambda);

        for (int i = 0; i < k; i++) {
            topK.push_back(vp[i].first);
        }
        return topK;
    }
};