class Solution {
public:
    string shiftingLetters(string s, vector<vector<int>>& shifts) {
        int n = s.size();
        vector<int> diff(n , 0); 

        for (const auto& shift : shifts)
        {
            int start = shift[0];
            int end = shift[1];
            int direction = shift[2];

            if (direction == 1)
            { 
                diff[start] += 1;
                if(end+1 < n) diff[end + 1] -= 1;
            }
            else
            { 
                diff[start] -= 1;
                if(end+1 < n) diff[end + 1] += 1;
            }
        }
        
        for (int i = 1; i < n; ++i)
        {
            diff[i] += diff[i - 1]; 
        }
        
        for (int i = 0; i < n; ++i)
        {
            int shift = diff[i] % 26; 
            if (shift < 0) shift += 26; 
            s[i] = ((s[i] - 'a' + shift) % 26) + 'a';
        }
        
        return s;
    }
};