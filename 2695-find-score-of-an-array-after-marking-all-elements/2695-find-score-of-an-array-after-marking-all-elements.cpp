class Solution {
public:
    long long findScore(vector<int>& nums) {
        int n = nums.size();
        
        long long score = 0;
  
        vector<pair<int,int>> vec(n);     
        for(int i=0 ; i<n ; i++)
        {
            vec[i] = {nums[i] , i};
        }
        sort(begin(vec) , end(vec));
        vector<bool> visited(n);
        for(int i=0 ; i<n ; i++)
        {
            int smallest = vec[i].first;
            int idx      = vec[i].second;

            if(visited[idx] != true)
            {
                score += smallest;
                if(idx-1 > -1) visited[idx-1] = true;
                if(idx+1 < n) visited[idx+1] = true;
            }

        }
        return score;
        
    }
};