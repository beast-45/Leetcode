class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> st(begin(nums),end(nums));
        int longest = 0;
        for(int num : st){
            if(st.find(num-1) == st.end()){
                int streak = 1;
                int currNum = num;
                while(st.find(currNum+1) != st.end()){
                    currNum += 1;
                    streak += 1;
                }
                longest = max(longest,streak);
            }
        }
        return longest;
    }
};