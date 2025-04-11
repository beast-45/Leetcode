class Solution {
public:
    int findTheWinner(int n, int k) {
        vector<int> nums;
        for(int i=1 ; i<=n ; i++){
            nums.push_back(i);
        }
        int i = 0;
        while(nums.size() > 1){
            int index = (i+k-1)%nums.size();
            nums.erase(begin(nums)+index);
            i = index;
        }
        return nums[0];
    }
};