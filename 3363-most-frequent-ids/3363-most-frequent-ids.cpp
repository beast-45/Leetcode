class Solution {
public:
    typedef pair<long long,long long> pairLL;
    vector<long long> mostFrequentIDs(vector<int>& nums, vector<int>& freq) {
        int n = nums.size();
        unordered_map<long long,long long> mp;
        priority_queue<pairLL> pq;
        vector<long long> result(n);
        for(int i=0 ; i<n ; i++){
            int id = nums[i];
            int frequency = freq[i];
            mp[id] += frequency;
            pq.push({mp[id],id});
            while(mp[pq.top().second] != pq.top().first) pq.pop();
            result[i] = (pq.size() == 0) ? 0 : pq.top().first;
        }
        return result;
    }
};