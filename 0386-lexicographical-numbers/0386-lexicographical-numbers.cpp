class Solution {
public:
    vector<int> lexicalOrder(int n) {
        auto lambda = [&](int &a , int &b)
        {
            string n1 = to_string(a);
            string n2 = to_string(b);
            return n2 > n1 ;
        };
        vector<int> nums;
        for(int i=1 ; i<=n ; i++)
        {
            nums.push_back(i);
        }
        sort(begin(nums) , end(nums) , lambda);
        return nums;  
    }
};