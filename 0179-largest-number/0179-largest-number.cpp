class Solution {
public:
    string largestNumber(vector<int>& nums) {
        string result = "";
        auto lambda = [&](int &a , int &b)
        {
            string s1 = to_string(a);
            string s2 = to_string(b);
            
            return s1+s2 > s2+s1;
        };

        sort(nums.begin() , nums.end() , lambda);

        if(nums[0]==0) return "0";

        for(int &num : nums)
        {
            result += to_string(num);
        }

        return result;
    }
};