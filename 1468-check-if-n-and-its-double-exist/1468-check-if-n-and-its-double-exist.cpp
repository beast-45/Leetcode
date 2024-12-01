class Solution {
public:
    bool checkIfExist(vector<int>& arr) {
        int n = arr.size();
        sort(begin(arr) , end(arr));
        int find;
        for(int i=0 ; i<n-1 ; i++)
        {
            find = arr[i]+arr[i];
            for(int j=0 ; j<n ; j++)
            {
                if(i!=j && arr[j]==find) return true;
            }
        }
        return false;
    }
};