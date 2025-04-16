class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string,int> mp;
        for(auto &word : words){
            mp[word]++;
        }
        vector<pair<string,int>> counts;
        for(auto &[word,freq] : mp){
            counts.push_back({word,freq});
        }
        sort(begin(counts),end(counts),[&](auto &p1 , auto &p2){
            if(p1.second == p2.second){
                return p1.first < p2.first;
            }
            return p1.second > p2.second;
        });
        vector<string> topKwords;
        for(int i=0 ; i<k ; i++){
            topKwords.push_back(counts[i].first);
        }
        return topKwords;
    }
};