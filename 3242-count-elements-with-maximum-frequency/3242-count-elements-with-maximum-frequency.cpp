class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        vector<int> freq(101,0);
        int maxf = 0;
        for(int &num : nums){
            freq[num]++;
            maxf = max(maxf,freq[num]);
        }
        int count = 0;
        for(int i=0 ; i<101 ; i++){
            if(freq[i] == maxf) count += 1;
        }
        return count*maxf;
    }
};