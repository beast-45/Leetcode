class Solution {
public:
    int numberOfAlternatingGroups(vector<int>& colors, int k) {
        int n = colors.size();
        int nn = n + (k - 1);
        int count = 0;
        colors.insert(colors.end(), colors.begin(), colors.begin() + (k - 1));
        int i = 0;
        int j = 1;
        while(j < nn){
            if(colors[j] == colors[j-1]){
                i = j;
                j += 1;
                continue;
            }
            if(j-i+1 == k){
                count += 1;
                i++;
            }
            j++;
        }
        return count;
    }
};