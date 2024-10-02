class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        int n = arr.size();
        set<int> st(arr.begin() , arr.end());
        unordered_map<int,int> mp;
        int c = 1;
        for(auto it : st)
        {
            mp[it] = c;
            c++;
        }
        for(int i=0 ; i<n ; i++)
        {
            arr[i] = mp[arr[i]];
        }
        return arr;
    }
};