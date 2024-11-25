class Solution {
public:
    int slidingPuzzle(vector<vector<int>>& board) {
        string start = "";
        for (int i = 0; i < 2; i++) {
            for (int j = 0; j < 3; j++) {
                start += to_string(board[i][j]);
            }
        }
        string target = "123450";
        queue<string> q;
        q.push(start);

        unordered_map<int, vector<int>> mp;
        mp[0] = {1, 3};
        mp[1] = {0, 2, 4};
        mp[2] = {1, 5};
        mp[3] = {0, 4};
        mp[4] = {1, 3, 5};
        mp[5] = {2, 4};

        unordered_set<string> visited;
        visited.insert(start);
        int level = 0;

        while (!q.empty())
        {
            int n = q.size();
            while (n--) {
                string curr = q.front();
                q.pop();
                if (curr == target) return level;
                int idxZero = curr.find('0');
                for (int swapidx : mp[idxZero])
                {
                    string newState = curr;
                    swap(newState[idxZero], newState[swapidx]);
                    if (visited.find(newState) == visited.end())
                    {
                        q.push(newState);
                        visited.insert(newState);
                    }
                }
            }
            level++;
        }
        return -1;
    }
};