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
            int sl = it-diff; // it = largest  , sl = Second Largest 
            if(st.find(sl) != st.end()  && st.find(sl-diff) != st.end()) count++; // Third Largest = sl-diff
        }
        return count;
    }
};


// BRUTEFORCE : 

class Solution {
public:
    int arithmeticTriplets(vector<int>& nums, int diff) {
        int n = nums.size();
        int tcount = 0;
        for(int i=0 ; i<n-2 ; i++)
        {
            for(int j=i+1 ; j<n-1 ; j++)
            {
                if(nums[j]-nums[i]==diff)
                {
                    for(int k=j+1 ; k<n ; k++)
                    {
                        if(nums[k]-nums[j]==diff) tcount++;
                    }
                }
            }
        }
        return tcount;
        
    }
};
