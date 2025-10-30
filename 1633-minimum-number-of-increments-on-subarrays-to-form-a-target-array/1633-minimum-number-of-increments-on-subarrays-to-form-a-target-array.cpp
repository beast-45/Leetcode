class Solution {
public:
    int minNumberOperations(vector<int>& target) {
        int n = target.size() , result = 0;
        int curr = 0 , prev = 0;
        for(int i=0 ; i<n ; i++){
            int curr = target[i];
            if(curr > prev){
                result += (curr-prev);
            }
            prev = curr;
        }
        return result;
    }
};