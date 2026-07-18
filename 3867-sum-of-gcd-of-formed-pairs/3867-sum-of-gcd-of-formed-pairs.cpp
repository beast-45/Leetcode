class Solution {
public:
    long long gcd(long long a , long long b){
        if(a < b) return gcd(b,a);
        if(b == 0) return a;
        return gcd(b,a%b);
    }
    long long gcdSum(vector<int>& nums) {
        int n = nums.size();
        long long result = 0;
        int mx = 0;
        vector<int> pgcd;
        for(int i=0 ; i<n ; i++){
            mx = max(mx,nums[i]);
            pgcd.push_back(gcd(mx,nums[i]));
        }
        sort(begin(pgcd),end(pgcd));
        int l = 0 , r = n-1;
        while(l<r){
            result += gcd(pgcd[l],pgcd[r]);
            l++;
            r--;
        }
        return result;        
    }
};