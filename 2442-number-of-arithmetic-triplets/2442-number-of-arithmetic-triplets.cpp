class Solution {
public:
    int arithmeticTriplets(vector<int>& nums, int diff) {
        int n = nums.size();
        int count = 0;
        unordered_set<int> st;
        for(int i=n-1 ; i>=0 ; i--)
        {
            st.insert(nums[i]);
        }
        for(auto it : st)
        {
            int sl = it-diff;
            if(st.find(sl) != st.end()  && st.find(sl-diff) != st.end()) count++;
        }
        return count;
    }
};