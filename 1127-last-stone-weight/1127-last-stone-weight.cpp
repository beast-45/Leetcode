class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> pq(begin(stones),end(stones));
        while(pq.size() > 1){
            int largestStone = pq.top();
            pq.pop();
            int secondLargestStone = pq.top();
            pq.pop();
            if(largestStone != secondLargestStone){
                pq.push(largestStone-secondLargestStone);
            }
        }
        return pq.empty() ? 0 : pq.top();
    }
};