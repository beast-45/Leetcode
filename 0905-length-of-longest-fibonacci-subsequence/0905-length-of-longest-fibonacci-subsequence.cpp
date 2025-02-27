class Solution {
public:
    int solve(int j , int k , vector<int> &arr , unordered_map<int,int> &mp){
        int target = arr[k] - arr[j];
        if(mp.count(target) && mp[target] < j){
            int i = mp[target];
            return solve(i , j , arr , mp) + 1;
        } 
        return 2;
    }
    int lenLongestFibSubseq(vector<int>& arr) {
        int n = arr.size();
        unordered_map<int,int> mp;
        int maxLen = 0;
    
        for(int i=0 ; i<n ; i++){
            mp[arr[i]] = i;
        }

        for(int j=0 ; j<n ; j++){
            for(int k=j+1 ; k<n ; k++){
                int length = solve(j , k , arr , mp);
                if(length >= 3){
                    maxLen = max(maxLen , length);
                }
            }
        }
        return maxLen;
        
    }
};