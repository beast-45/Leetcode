class Solution {
public:
    int n;
    int t[2][101][101];
    int solveForAlice(vector<int>& piles, int person, int i, int M) { 
        if(i >= n) return 0;
        if(t[person][i][M] != -1) return t[person][i][M];
        int result = (person == 1) ? -1 : INT_MAX;
        int stones = 0;
        for(int x = 1; x <= min(2*M, n-i); x++) {  
            stones += piles[i+x-1];
            if(person == 1) {
                result = max(result, stones + solveForAlice(piles, 0, i+x, max(M, x)));
            } else { 
                result = min(result, solveForAlice(piles, 1, i+x, max(M, x)));
            }
        }   
        return t[person][i][M] = result;
    }  
    int stoneGameII(vector<int>& piles) {
        n = piles.size();
        memset(t,-1,sizeof(t));
        return solveForAlice(piles,1,0,1);
    }
};