class Solution {
public:
    long long maxKelements(vector<int>& nums, int k) {
        long long score = 0;
        priority_queue<int> pq(begin(nums) , end(nums));
        while(k--)
        {
            int maxE =  pq.top();
            pq.pop();
            score += maxE;
            maxE = ceil(maxE/3.0);
            pq.push(maxE);
        }
        return score;
        
    }
};