class Solution {
public:
    int addedInteger(vector<int>& nums1, vector<int>& nums2) {
        sort(nums1.begin(),nums1.end());
        sort(begin(nums2),end(nums2));
        return nums2[0]-nums1[0];
        
    }
};