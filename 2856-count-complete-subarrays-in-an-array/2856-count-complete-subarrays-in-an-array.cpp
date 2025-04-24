class Solution {
public:
    int countCompleteSubarrays(vector<int>& nums) {
        int n = nums.size();
        set<int> st;
        for(int &num : nums){
            st.insert(num);
        }
        int uniqueElements = st.size();
        int i = 0;
        int j = 0;
        int count = 0;
        unordered_map<int,int> mp;
        while(j<n){
            mp[nums[j]]++;
            while(mp.size() == uniqueElements){
                count += n-j;
                mp[nums[i]]--;
                if(mp[nums[i]] == 0) mp.erase(nums[i]);
                i++;
            }
            j++;
        }
        return count;
    }
};