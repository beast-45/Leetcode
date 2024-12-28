class Solution {
public:
    int t[20001][4];
    int sum(vector<int> &subArraySum , int count , int i , int k)
    {
        if(count == 0) return 0;
        if(i >= subArraySum.size()) return INT_MIN;

        if(t[i][count] != -1) return t[i][count];

        int take = subArraySum[i] + sum(subArraySum , count-1 , i+k , k);
        int notTake = sum(subArraySum , count , i+1 , k);

        return t[i][count] = max(take , notTake);
    }

    void solve(vector<int> &subArraySum , int count , int i , int k , vector<int> &result)
    {
        if(count == 0) return;
        if(i >= subArraySum.size()) return;

        int take_i = subArraySum[i] + sum(subArraySum , count-1 , i+k , k);
        int notTaking_i = sum(subArraySum , count , i+1 , k);

        if(take_i >= notTaking_i)
        {
            result.push_back(i);
            solve(subArraySum , count-1 , i+k , k , result);
        }else{
            solve(subArraySum , count , i+1 , k , result);
        }
    }

    vector<int> maxSumOfThreeSubarrays(vector<int>& nums, int k) {
        int n = nums.size();
        memset(t , -1 , sizeof(t));
        vector<int> subArraySum;

        int i = 0;
        int j = 0;
        int winSum = 0;

        while(j<n)
        {
            winSum += nums[j];
            if(j-i+1 == k)
            {
                subArraySum.push_back(winSum);
                winSum -= nums[i];
                i++;
            }  
            j++;
        }
        vector<int> result;
        solve(subArraySum , 3 , 0 , k , result);
        return result;
    }
};