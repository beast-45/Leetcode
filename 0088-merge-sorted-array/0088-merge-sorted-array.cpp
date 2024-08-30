class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int j=0; 
        int i=m;
        while(i<m+n)
        {
            nums1[i]=nums2[j];
            i++;
            j++;
        }
        sort(nums1.begin() , nums1.end());
    }
};