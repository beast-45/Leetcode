class Solution {
public:
    int countDigits(int n){
        int count = 0;
        while(n){
            count += 1;
            n /= 10;
        }
        return count;
    }
    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
        unordered_map<int,int> mp;
        for(int &num : arr1){
            mp[num] = countDigits(num);
            while(num){
                num /= 10;
                mp[num] = countDigits(num);
            }
        }
        int maxLen = 0;
        for(int &num : arr2){
            if(mp.find(num) != mp.end()){
                maxLen = max(maxLen,mp[num]);
            }
            while(num){
                num /= 10;
                if(mp.find(num) != mp.end()){
                    maxLen = max(maxLen,mp[num]);
                }
            }
        }
        return maxLen;
    }
};