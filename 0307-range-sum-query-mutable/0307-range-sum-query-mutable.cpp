class NumArray {
public:
    int n;
    vector<int> segtree;
    void buildSegTree(int i , int l , int r , vector<int> &nums){
        if(l == r){
            segtree[i] = nums[l];
            return;
        }
        int mid = l+(r-l)/2;
        buildSegTree(2*i+1,l,mid,nums);
        buildSegTree(2*i+2,mid+1,r,nums);
        segtree[i] = segtree[2*i+1] + segtree[2*i+2];
    }
    void updateSegTree(int index , int value , int i , int l , int r){
        if(l == r){
            segtree[i] = value;
            return;
        }
        int mid = l+(r-l)/2;
        index <= mid ? updateSegTree(index,value,2*i+1,l,mid) : updateSegTree(index,value,2*i+2,mid+1,r);
        segtree[i] = segtree[2*i+1] + segtree[2*i+2];
    }
    int querySegTree(int start , int end , int i , int l , int r){
        if(l>end || r<start) return 0;
        if(l>=start && r<=end) return segtree[i];
        int mid = l+(r-l)/2;
        return querySegTree(start,end,2*i+1,l,mid) + querySegTree(start,end,2*i+2,mid+1,r);
    }
    NumArray(vector<int>& nums) {
        n = nums.size();
        segtree.resize(4*n);
        buildSegTree(0,0,n-1,nums);
    }
    
    void update(int index, int val) {
        updateSegTree(index,val,0,0,n-1);
    }
    
    int sumRange(int left, int right) {
        return querySegTree(left,right,0,0,n-1);
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */