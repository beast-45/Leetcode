class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        int n = nums.size();
        int op = 0;
        priority_queue<long long , vector<long long> , greater<long long>> pq(begin(nums) , end(nums));
        while(pq.size() >= 2 && pq.top() < k){
            long long a = pq.top();
            pq.pop();
            long long b = pq.top();
            pq.pop();
            pq.push(2*a+b);
            op += 1;
        }
        return op;
    }
};