class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        vector<int> tmp;
        for(int i=0 ; i<m ; i++)
        {
            tmp.push_back(nums1[i]);
        }
        for(int &num : nums2)
        {
            tmp.push_back(num);
        }
        sort(begin(tmp),end(tmp));
        nums1 = tmp;
        
    }
};