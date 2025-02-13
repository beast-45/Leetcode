class Solution {
public:
    long long maxKelements(vector<int>& nums, int k) {
        long long score = 0;
        priority_queue<int> pq(begin(nums) , end(nums));
        while(k--){
            int largest =  pq.top();
            pq.pop();
            score += largest;
            pq.push(ceil(largest/3.0));
        }
        return score;
        
    }
};