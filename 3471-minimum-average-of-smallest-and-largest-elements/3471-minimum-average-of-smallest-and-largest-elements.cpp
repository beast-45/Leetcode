class Solution {
public:
    double minimumAverage(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin() , nums.end());
        vector<double> averages;
        int i=0 ; 
        int j=n-1;
        while(i<j)
        {
            double avg = double(nums[i]+nums[j])/2;
            averages.push_back(avg);
            i++;
            j--;
        }
        sort(begin(averages) , end(averages));
        return averages[0];
        
    }
};