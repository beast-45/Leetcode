class Solution {
public:
    int minStoneSum(vector<int>& piles, int k) {
        priority_queue<int> pq(begin(piles), end(piles));
        int sum = accumulate(piles.begin(), piles.end(), 0); 
        while (k-- && !pq.empty()) {
            int largest = pq.top();
            pq.pop();
            int stonesRemoved = largest / 2;
            sum -= stonesRemoved;
            pq.push(largest - stonesRemoved);
        }
        return sum;
    }
};