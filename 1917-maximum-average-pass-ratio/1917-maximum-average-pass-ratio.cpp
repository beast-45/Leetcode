class Solution {
public:
    #define P pair<double,int>
    double maxAverageRatio(vector<vector<int>>& classes, int extraStudents) {
        int n = classes.size();

        priority_queue<P> pq;

        for(int i=0 ; i<n ; i++)
        {
            double currentPR = (double)classes[i][0]/classes[i][1];
            double updatedPR = (double)(classes[i][0]+1)/(classes[i][1]+1);
            double improvement = updatedPR - currentPR;
            pq.push({improvement , i});
        }

        while(extraStudents--)
        {
            auto curr = pq.top();
            pq.pop();

            double delta = curr.first;
            int idx      = curr.second;

            classes[idx][0] += 1;
            classes[idx][1] += 1;
            double currentPR = (double)classes[idx][0]/classes[idx][1];
            double updatedPR = (double)(classes[idx][0]+1)/(classes[idx][1]+1);
            delta = updatedPR - currentPR;
            pq.push({delta , idx});
        }
        double result = 0.0;
        for(int i=0 ; i<n ; i++)
        {
            result += (double)classes[i][0]/classes[i][1];
        }
        return result/n;
    }
};