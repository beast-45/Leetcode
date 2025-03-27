class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n = nums.size();
        int count1 = 0;
        int majElement1 = NULL;
        int count2 = 0;
        int majElement2 = NULL;
        for(int i=0 ; i<n ; i++){
            if(nums[i] == majElement1){
                count1++;
            }
            else if(nums[i] == majElement2){
                count2++;
            }
            else if(count1 == 0){
                majElement1 = nums[i];
                count1 = 1;
            }
            else if(count2 == 0){
                majElement2 = nums[i];
                count2 = 1;
            }
            else{
                count1--;
                count2--;
            }
        }
        vector<int> result;
        int freq1 = 0;
        int freq2 = 0;
        for(int &num : nums){
            if(num == majElement1){
                freq1++;
            }
            else if(num == majElement2){
                freq2++;
            }
        }
        if(freq1 > floor(n/3)){
            result.push_back(majElement1);
        }
        if(freq2 > floor(n/3)){
            result.push_back(majElement2);
        }
        return result;
    }
};