class Solution {
public:
    typedef pair<int,char> P;
    string longestDiverseString(int a, int b, int c) {
        priority_queue<P , vector<P>> pq;
        if(a>0)
        {
            pq.push({a , 'a'});
        }
        if(b>0)
        {
            pq.push({b , 'b'});
        }
        if(c>0)
        {
            pq.push({c , 'c'});
        }
        string result = "";

        while(!pq.empty())
        {
            int currCount =  pq.top().first;
            int currChar  =  pq.top().second;
            pq.pop();
            int n = result.length();

            if(n >= 2 && result[n-1] == currChar && result[n-2] ==  currChar)
            {
                if(pq.empty()) break;
                int nxtCount = pq.top().first;
                int nxtChar  = pq.top().second;
                pq.pop();
                result.push_back(nxtChar);
                nxtCount--;
                if(nxtCount > 0) pq.push({nxtCount , nxtChar}); 
            }
            else
            {
                currCount--;
                result.push_back(currChar);
            }
            if(currCount>0) pq.push({currCount , currChar});
        }
        return result;
    }
};