class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
        int n = arr.size() , minDiff = INT_MAX;
        sort(begin(arr),end(arr));
        for(int i=1 ; i<n ; i++){
            minDiff = min(minDiff,arr[i]-arr[i-1]);
        }
        vector<vector<int>> result;
        for(int i=1 ; i<n ; i++){
            if(arr[i]-arr[i-1] == minDiff) result.push_back({arr[i-1],arr[i]});
        }
        return result;
    }
};