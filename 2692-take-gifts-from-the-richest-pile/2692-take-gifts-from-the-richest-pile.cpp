class Solution {
public:
    long long pickGifts(vector<int>& gifts, int k) {
        priority_queue<int> pq;
        for(int &gift : gifts)
        {
            pq.push(gift);
        }

        for(int i=0 ; i<k ; i++)
        {
            int maxE = pq.top();
            pq.pop();
            int remE = floor(sqrt(maxE));
            pq.push(remE);
        }

        long long remGifts = 0;
        while(!pq.empty())
        {
            remGifts += pq.top();
            pq.pop();
        }
        return remGifts;  
    }
};