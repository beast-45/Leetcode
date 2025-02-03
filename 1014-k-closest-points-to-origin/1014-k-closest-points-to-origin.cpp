class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        vector<double> distances;
        vector<vector<int>> result;
        vector<pair<double, pair<int, int>>> mapper;
        for (auto& p : points) {
            int x = p[0];
            int y = p[1];
            double d = sqrt(x * x + y * y);
            mapper.push_back({d, {x, y}});
        }
        sort(begin(mapper), end(mapper));
        for (int i = 0; i < k; i++) {
            result.push_back({mapper[i].second.first , mapper[i].second.second});
        }
        return result;
    }
};
