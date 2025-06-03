class NumArray {
public:
    vector<int> prefSum;
    NumArray(vector<int>& nums) {
        int n = nums.size();
        prefSum.resize(n);
        prefSum[0] = nums[0];
        for(int i=1 ; i<n ; i++){
            prefSum[i] = prefSum[i-1] + nums[i];
        }
    }
    
    int sumRange(int left, int right) {
        if(left == 0) return prefSum[right];
        return prefSum[right] - prefSum[left-1];
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */