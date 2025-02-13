class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int> pq(begin(nums),end(nums));
        while(k-1){
            pq.pop();
            k--;
        }
        return pq.top(); 
    }
};