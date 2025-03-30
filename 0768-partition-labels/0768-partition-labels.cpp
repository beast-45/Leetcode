class Solution {
public:
    vector<int> partitionLabels(string s) {
        int n = s.length();
        vector<int> lastOccurence(26,-1);
        for(int i=0 ; i<n ; i++){
            int index = s[i]-'a';
            lastOccurence[index] = i;
        }
        int i = 0;
        vector<int> result;
        while(i < n){
            int end = lastOccurence[s[i]-'a'];
            int j = i;
            while(j < end){
                end = max(end,lastOccurence[s[j]-'a']);
                j++;
            }
            result.push_back(j-i+1);
            i = j+1;
        }
        return result;
    }
};