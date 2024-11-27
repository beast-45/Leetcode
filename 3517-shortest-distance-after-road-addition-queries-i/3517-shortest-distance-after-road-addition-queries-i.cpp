class Solution {
public:
    unordered_map<int, vector<int>> adj;

    int bfs(int n) {
        queue<int> que;
        que.push(0);
        vector<bool> visited(n, false);
        visited[0] = true;

        int level = 0;
        while (!que.empty()) {
            int size = que.size();
            while (size--) {
                int node = que.front();
                que.pop();

                if (node == n - 1) {
                    return level; 
                }

                for (int neighbor : adj[node]) {
                    if (!visited[neighbor]) {
                        que.push(neighbor);
                        visited[neighbor] = true;
                    }
                }
            }
            level++;
        }
        return -1; 
    }

    vector<int> shortestDistanceAfterQueries(int n, vector<vector<int>>& queries) {
        adj.clear();

        for (int i = 0; i < n - 1; i++) {
            adj[i].push_back(i + 1);
        }

        int k = queries.size();
        vector<int> res(k);
        for (int i = 0; i < k; i++) {
            adj[queries[i][0]].push_back(queries[i][1]);
            res[i] = bfs(n);
        }
        return res;
    }
};