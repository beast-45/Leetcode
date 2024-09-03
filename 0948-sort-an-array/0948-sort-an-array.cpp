class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        unordered_map<int,int> mp;
        for(int &num : nums)
        {
            mp[num]++;
        }
        int minE = *min_element(begin(nums),end(nums));
        int maxE = *max_element(begin(nums),end(nums));

        int i=0;
        for(int num=minE ; num<=maxE ; num++)
        {
            while(mp[num]>0)
            {
                nums[i]=num;
                i++;
                mp[num]--;
            }
        }    
        return nums;   
    }
};