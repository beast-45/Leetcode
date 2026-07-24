class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums) {
        int n = nums.size();
        unordered_set<int> st;
        for(int i=0 ; i<n ; i++){
            for(int j=i ; j<n ; j++){
                st.insert(nums[i]^nums[j]);
            }
        }
        unordered_set<int> uniqueXORs;
        for(int &num : nums){
            for(int pairXOR : st){
                uniqueXORs.insert(num^pairXOR);
            }
        }
        return uniqueXORs.size();
    }
};