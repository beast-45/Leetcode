class Solution {
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
        int n = arr.size();
        vector<int> result;
        for(int i=1 ; i<n ; i++)
        {
            arr[i] = arr[i-1]^arr[i];
        }

        for(vector<int> &query : queries)
        {
            int L = query[0];
            int R = query[1];

            int xval = arr[R]^(L==0? 0 : arr[L-1]);
            result.push_back(xval);
        }
        return result;
    }
};