class Solution {
public:
    int binSearch(vector<int>& nums, int start, int end, int target) {
        if (start > end) {
            return -1;
        }
        int mid = start + (end - start) / 2;
        if (nums[mid] == target) {
            return mid;
        }
        if (nums[mid] > target) {
            return binSearch(nums, 0, mid - 1, target);

        } else {
            return binSearch(nums, mid + 1, end, target);
        }
    }
    int search(vector<int>& nums, int target) {
        return binSearch(nums, 0, nums.size() - 1, target);
    }
};