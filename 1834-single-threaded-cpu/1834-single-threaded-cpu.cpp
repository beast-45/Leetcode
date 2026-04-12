class Solution {
public:
    typedef pair<int,int> P;
    vector<int> getOrder(vector<vector<int>>& tasks) {
        int n = tasks.size();
        vector<vector<int>> sTasks;                //Sorted Tasks
        for(int i=0 ; i<n ; i++){
            int eTime = tasks[i][0] , pTime = tasks[i][1];
            sTasks.push_back({eTime,pTime,i});
        }
        sort(begin(sTasks),end(sTasks));
        priority_queue<P,vector<P>,greater<P>> pq;
        vector<int> result;
        int index = 0;
        long long currTime = 0;
        while(index < n || !pq.empty()){
            if(pq.empty() && currTime < sTasks[index][0]){
                currTime = sTasks[index][0];
            }
            while(index < n && sTasks[index][0] <= currTime){
                pq.push({sTasks[index][1],sTasks[index][2]});
                index += 1;
            }
            auto [processingTime,position] = pq.top();
            pq.pop();
            currTime += processingTime;
            result.push_back(position);
        }
        return result;
    }
};