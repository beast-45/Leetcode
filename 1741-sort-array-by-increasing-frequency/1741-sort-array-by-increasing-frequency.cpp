bool cmp(const pair<int , int> &a , const pair<int,int> &b)
{
    if(a.second == b.second)
    {
        return a.first > b.first;
    }
    return a.second < b.second;
}
class Solution {
public:
    vector<int> frequencySort(vector<int>& nums) {
        unordered_map<int ,int> mp;
        for(int & num : nums)
        {
            mp[num]++;
        }
        vector<pair<int , int>> valfreq;
        for(auto m : mp)
        {
            valfreq.push_back(m);
        }
        sort(valfreq.begin() , valfreq.end() , cmp);
        vector<int> res;
        for(auto v : valfreq)
        {
            for(int i=0 ; i<v.second ; i++)
            {
                res.push_back(v.first);
            }
        }
        return res;
        
    }
};