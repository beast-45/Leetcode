class Solution {
public:
    bool canAliceWin(vector<int>& nums) {
        int n = nums.size();
        int sinDigSum = 0;
        int douDigSum = 0;
        for(int &num : nums)
        {
            if(num<10) sinDigSum += num;
            else douDigSum += num;
        }
        if(sinDigSum ==  douDigSum) return false;
        return true;
        
    }
};