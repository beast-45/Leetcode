class Solution {
public:
    int t[100001];
    const int m = 1e9+7;
    int solve(int low , int high , int z , int o , int length)
    {
        if(length > high) return 0;
        bool add1 = false;
        if(length >= low && length <= high) add1 = true;

        if(t[length] != -1) return t[length];
        

        int zeroAppended = solve(low , high , z , o , length+z);
        int oneAppended  = solve(low , high , z , o , length+o);

        return t[length] = (add1 + zeroAppended + oneAppended)%m;
    }
    int countGoodStrings(int low, int high, int zero, int one) {
        memset(t , -1 , sizeof(t));
        return solve(low , high , zero , one , 0);
    }
};