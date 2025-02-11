class Solution {
public:
    long long minimumTime(vector<int>& time, int totalTrips) {
        int n = time.size();
        long long i = 1;
        long long j = *min_element(time.begin(), time.end()) * (long long)totalTrips;

        while (i < j) {
            long long mid = i + (j - i) / 2;
            long long t = 0;

            for (int j = 0; j < n; j++) {  
                t += mid / time[j];
                if (t >= totalTrips) break;  
            }

            if (t >= totalTrips) {
                j = mid;
            } else {
                i = mid + 1;
            }
        }
        return i;
    }
};
