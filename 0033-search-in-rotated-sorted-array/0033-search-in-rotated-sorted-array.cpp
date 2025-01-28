class Solution {
public:
    int binSearch(vector<int>& nums, int l, int h, int target) {
        while (l <= h) {
            int mid = (l + h) / 2;
            if (nums[mid] == target) {
                return mid;
            } else if (nums[l] <= nums[mid]) {
                if (nums[l] <= target && target <= nums[mid]) {
                    h = mid - 1;
                } else {
                    l = mid + 1;
                }
            } else {
                if (nums[mid] <= target && target <= nums[h]) {
                    l = mid + 1;
                } else {
                    h = mid - 1;
                }
            }
        }
        return -1;
    }

    int search(vector<int>& nums, int target) {
        int n = nums.size();
        return binSearch(nums, 0, n - 1, target);
    }
};