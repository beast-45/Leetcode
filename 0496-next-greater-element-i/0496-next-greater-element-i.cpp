class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        int n = nums2.size();
        vector<int> nxtGreaterElement(n);
        stack<int> st;
        for(int i=n-1 ; i>=0 ; i--){
            if(st.empty()){
                nxtGreaterElement[i] = -1;
            }
            else if(st.top() > nums2[i]){
                nxtGreaterElement[i] = st.top();
            }
            else{
                while(!st.empty() && st.top() <= nums2[i]){
                    st.pop();
                }
                nxtGreaterElement[i] = st.empty() ? -1 : st.top();
            }
            st.push(nums2[i]);
        }
        unordered_map<int,int> mp;
        for(int i=0 ; i<n ; i++){
            mp[nums2[i]] = nxtGreaterElement[i];
        }
        vector<int> result(nums1.size());
        for(int i=0 ; i<nums1.size() ; i++){
            result[i] = mp[nums1[i]];
        }
        return result;  
    }
};