class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int i = 0;
        int j = 0;
        int n1 = nums1.size();
        int n2 = nums2.size();
        vector<int> nums;
        while(i<n1 && j<n2){
            if(nums1[i]<=nums2[j]){
                nums.push_back(nums1[i]);
                i++;
            }
            else{
                nums.push_back(nums2[j]);
                j++;
            }
        }
        while(i < n1){
            nums.push_back(nums1[i]);
            i++;
        }
        while(j < n2){
            nums.push_back(nums2[j]);
            j++;
        }
        int n = nums.size();
        double median = 0.0;
        if(n%2 == 1){
            int mid = n/2;
            return (double)nums[mid];
        }
        else{
            int mid = n/2;
            double midE = nums[mid];
            double midm1E = nums[mid-1];
            median = (midE+midm1E)/2;
        }
        return median;
    }
};