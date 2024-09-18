class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        int n = nums.size();
        unordered_map<long,int> mapArr[n];
        int result = 0 ;
        
        for(int i=0 ; i<n ; i++)
        {
            for(int j=0 ; j<i ; j++)
            {
                long difference = (long)nums[i]-nums[j];
                auto it = mapArr[j].find(difference);
                int countAtj = it == end(mapArr[j])? 0 : it->second;
                mapArr[i][difference] += countAtj+1;
                result += countAtj;

            }
        }
        return result;
        
    }
};