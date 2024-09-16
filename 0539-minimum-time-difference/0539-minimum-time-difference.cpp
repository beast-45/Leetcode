class Solution {
public:
    int findMinDifference(vector<string>& timePoints) {
        int n = timePoints.size();
        vector<int> mins(n);

        for(int i=0 ; i<n ; i++)
        {
            string time = timePoints[i];
            string hours = time.substr(0,2);
            string minutes = time.substr(3);
            int hh = stoi(hours);
            int mm = stoi(minutes);
            mins[i] = hh*60 + mm;
        }
        sort(mins.begin(), mins.end());
        int result = INT_MAX;
        for(int i=1 ; i<n ; i++)
        {
            result = min(result , mins[i]-mins[i-1]);
        }
        return min(result , 1440-mins[n-1]+mins[0]);
    }
};