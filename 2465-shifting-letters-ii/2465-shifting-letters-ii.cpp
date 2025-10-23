class Solution {
public:
    string shiftingLetters(string s, vector<vector<int>>& shifts) {
        int n = s.length();
        vector<int> diff(n,0);
        for(auto &shift : shifts){
            int l = shift[0] , r = shift[1] , direction = shift[2];
            if(direction == 1){
                diff[l] += 1;
                if(r+1 < n) diff[r+1] -= 1; 
            }else{
                diff[l] -= 1;
                if(r+1 < n) diff[r+1] += 1;
            }
        }
        for(int i=1 ; i<n ; i++){
            diff[i] += diff[i-1];
        }
        for(int i=0 ; i<n ; i++){
            int shift = diff[i] % 26;
            if(shift < 0) shift += 26;
            s[i] = ((s[i]-'a' + shift)%26) + 'a';
        }
        return s;   
    }
};