class Solution {
public:
    vector<int> countServers(int n, vector<vector<int>>& logs, int x, vector<int>& queries) {
        int tn = logs.size();
        sort(begin(logs),end(logs),[&](auto &l1 , auto &l2){
            return l1[1]<l2[1];
        });
        vector<vector<int>> que;
        for(int i=0 ; i<queries.size() ; i++){
            que.push_back({queries[i],i});
        }
        sort(begin(que),end(que),[&](auto &q1 , auto &q2){
            return q1[0]<q2[0];
        });
        vector<int> result(que.size());
        unordered_map<int,int> mp;
        int l = 0 , r = 0;
        for(auto &q : que){
            int startTime = q[0]-x , endTime = q[0];
            while(r<tn && logs[r][1] <= endTime){
                mp[logs[r][0]] += 1;
                r++;
            }
            while(l<tn && logs[l][1] < startTime){
                mp[logs[l][0]] -= 1;
                if(mp[logs[l][0]] == 0) mp.erase(logs[l][0]);
                l++;
            }
            int received = mp.size();
            result[q[1]] = n - received;
        }
        return result;
    }
};

