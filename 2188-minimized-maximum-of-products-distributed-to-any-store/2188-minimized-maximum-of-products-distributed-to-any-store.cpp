class Solution {
public:
    bool possibleToDistribute(int x , vector<int> &quantities , int shops)
    {
        for(int &products : quantities)
        {
            shops -= (products + x -1)/x;
            if(shops < 0) return false;
        }
        return true;
    }

    int minimizedMaximum(int n, vector<int>& quantities) {
        int l = 1;
        int r = *max_element(begin(quantities) , end(quantities));

        int result = 0;

        while(l <= r)
        {
            int mid = l + (r - l)/2;
            if(possibleToDistribute(mid , quantities , n))
            {
                result = mid;
                r = mid-1;
            }
            else
            {
                l = mid+1;
            }
        }
        return result;
    }
};