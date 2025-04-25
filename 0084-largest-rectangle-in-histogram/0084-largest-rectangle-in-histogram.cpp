class Solution {
public:
    void makeNSR(int n , vector<int> &nums , vector<int> &nsr){
        stack<int> st;
        for(int i=n-1 ; i>=0 ; i--){
            while(!st.empty() && nums[st.top()] >= nums[i]){
                st.pop();
            }
            nsr[i] = st.empty() ? n : st.top();
            st.push(i);
        }
    }
    void makeNSL(int n , vector<int> &nums , vector<int> &nsl){
        stack<int> st;
        for(int i=0 ; i<n ; i++){
            while(!st.empty() && nums[st.top()] >= nums[i]){
                st.pop();
            }
            nsl[i] = st.empty() ? -1 : st.top();
            st.push(i);
        }
    }
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        vector<int> nsl(n) , nsr(n);
        makeNSL(n,heights,nsl);
        makeNSR(n,heights,nsr);
        int maxArea = INT_MIN;
        for(int i=0 ; i<n ; i++){
            int area = heights[i] * (nsr[i]-nsl[i]-1);
            maxArea = max(maxArea,area);
        }
        return maxArea;
    }
};