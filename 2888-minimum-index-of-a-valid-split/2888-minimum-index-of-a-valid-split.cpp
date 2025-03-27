class Solution {
public:
    int minimumIndex(vector<int>& nums) {
        int n = nums.size();
        int countME = 0;
        int majElement = -1;
        for(int i=0 ; i<n ; i++){
            if(countME == 0){
                majElement = nums[i];
                countME = 1;
            }
            else if(nums[i] == majElement){
                countME++;
            }
            else{
                countME--;
            }
        }
        int majElCount = count(begin(nums),end(nums),majElement);
        int leftMEcount = 0;
        for(int i=0 ; i<n-1 ; i++){
            if(nums[i] == majElement){
                leftMEcount += 1;
                int rightMEcount = majElCount-leftMEcount;
                int n1 = i+1;
                int n2 = n-i-1;
                if(leftMEcount > n1/2 && rightMEcount > n2/2){
                    return i;
                }
            }
        }
        return -1;
    }
};