class Solution {
public:
    int minimumRecolors(string blocks, int k) {
        int n = blocks.size();
        int i = 0;
        int j = 0;
        int wb = 0;
        int bb = 0;
        int minwb = INT_MAX;
        while (j < n) {
            if (blocks[j] == 'W') {
                wb++;
            } else {
                bb++;
            }
            if (j - i + 1 == k) {
                minwb = min(wb, minwb);
                if (blocks[i] == 'W') {
                    wb--;
                } else {
                    bb--;
                }
                i++;
            }
            j++;
        }
        return minwb;
    }
};