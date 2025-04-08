class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        int n = nums.size();
        unordered_set<int> st;
        for(int i=n-1 ; i>=0 ; i--){
            if(st.find(nums[i]) != st.end()){
                int size = i+1;
                return size%3 == 0 ? size/3 : (size/3)+1; 
            }
            else{
                st.insert(nums[i]);
            }
        }
        return 0;
    }
};