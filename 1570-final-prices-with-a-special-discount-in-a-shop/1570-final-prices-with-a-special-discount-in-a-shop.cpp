class Solution {
public:
    vector<int> finalPrices(vector<int>& prices) {
        int n = prices.size();
        for(int i=0 ; i<n-1 ; i++)
        {
            for(int j=i+1 ; j<n ; j++)
            {
                if(prices[i] >= prices[j])
                {
                    prices[i] -= prices[j];
                    break;
                }
            }
        }
        return prices;
        
    }
};