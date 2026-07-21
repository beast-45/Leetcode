class Solution {
public:
    int maxActiveSectionsAfterTrade(string s) {
        int n = s.length();
        int ones = 0 , i = 0;
        vector<int> zeroBlocks;
        while(i<n){
            if(s[i] == '1'){
                ones += 1;
                i++;
            }
            else{
                int start = i;
                while(i<n && s[i] == '0') i++;
                zeroBlocks.push_back(i-start);
            }
        }
        int maxPairSum = 0;
        for(int i=1 ; i<zeroBlocks.size() ; i++){
            maxPairSum = max(maxPairSum,zeroBlocks[i] + zeroBlocks[i-1]);
        }
        return maxPairSum + ones;
    }
};