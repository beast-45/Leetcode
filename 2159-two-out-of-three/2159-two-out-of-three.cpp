class Solution {
public:
    vector<int> twoOutOfThree(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3) {
        int a = nums1.size();
        int b = nums2.size();
        int c = nums3.size();

        vector<int> ans;
        unordered_set<int> st;

        for(int i=0 ; i<a ; i++)
        {
            for(int j=0 ; j<b ; j++)
            {
                if(nums1[i]==nums2[j]) st.insert(nums1[i]);
            }
            
        }
        for(int i=0 ; i<a ; i++)
        {
            for(int j=0 ; j<c ; j++)
            {
                if(nums1[i]==nums3[j]) st.insert(nums1[i]);
            }
        }
         for(int i=0 ; i<b ; i++)
        {
            for(int j=0 ; j<c ; j++)
            {
                if(nums2[i]==nums3[j]) st.insert(nums2[i]);
            }
        }
        for(auto it : st)
        {
            ans.push_back(it);
        }
        return ans;
            
        
    }
};