class Solution {
public:
    typedef pair<int,int> P;
    vector<int> busiestServers(int k, vector<int>& arrival, vector<int>& load) {
        int n = arrival.size();
        set<int> avlServers;
        for(int i=0 ; i<k ; i++){
            avlServers.insert(i);
        }
        priority_queue<P,vector<P>,greater<P>> pq;
        vector<int> servedReqs(k,0);
        for(int i=0 ; i<n ; i++){
            while(!pq.empty() && pq.top().first <= arrival[i]){
                int freed = pq.top().second;
                pq.pop();
                avlServers.insert(freed);
            }
            int reqServer = i%k;
            auto it = avlServers.lower_bound(reqServer);
            if (it == avlServers.end()) it = avlServers.begin(); // wrap around
            if(it == avlServers.end()) continue;
            int server = *it;
            avlServers.erase(it);
            pq.emplace(arrival[i]+load[i],server);
            servedReqs[server] += 1;
        }
        int maxNumberReqs = ranges::max(servedReqs);
        vector<int> result;
        for(int i=0 ; i<k ; i++){
            if(servedReqs[i] == maxNumberReqs) result.push_back(i);
        }
        return result;
    }
};