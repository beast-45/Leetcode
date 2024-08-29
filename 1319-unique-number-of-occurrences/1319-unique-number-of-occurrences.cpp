class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        vector<int> v;
        unordered_map<int,int> mp;
        for(int & num : arr)
        {
            mp[num]++;
        }
        for(auto it : mp)
        {
            v.push_back(it.second);
        }
        int n = v.size();
        sort(v.begin(),v.end());
        for(int i=0 ; i<n-1 ; i++)
        {
            if(v[i]==v[i+1]) return false;
        }
        return true;

        
    }
};