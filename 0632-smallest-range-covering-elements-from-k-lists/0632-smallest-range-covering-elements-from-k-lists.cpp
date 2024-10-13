class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {
        int k = nums.size();
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;

        int maxEl = INT_MIN;
        for(int i = 0; i < k; i++) {
            pq.push({nums[i][0], i, 0});
            maxEl = max(maxEl, nums[i][0]);
        }

        vector<int> resultRange = {-1000000, 1000000};

        while(!pq.empty()) {
            vector<int> curr = pq.top();
            pq.pop();

            int minEl = curr[0];
            int listIdx = curr[1];
            int idx     = curr[2];

            if(maxEl - minEl < resultRange[1] -  resultRange[0]) {
                resultRange[0] = minEl;
                resultRange[1] = maxEl;
            }

            if(idx+1 < nums[listIdx].size()) {
                int nextElement = nums[listIdx][idx+1];
                pq.push({nextElement, listIdx, idx+1});
                maxEl = max(maxEl, nextElement);
            } else {
                break;
            }
        }

        return resultRange;
    }
};