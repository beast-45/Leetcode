class Solution {
public:
    int findLucky(vector<int>& arr) {
        unordered_map<int,int> mp;
        for(auto &num : arr){
            mp[num]++;
        }
        int result = -1;
        for(int i=0 ; i<arr.size() ; i++){
            if(mp[arr[i]] == arr[i]){
                result = max(result,arr[i]);
            }
        }
        return result;
    }
};