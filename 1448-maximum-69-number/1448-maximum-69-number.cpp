class Solution {
public:
    int maximum69Number (int num) {
        string n = to_string(num);
        int s = n.size();
        for(int i=0 ; i<s ; i++)
        {
            if(n[i]=='6')
            {
                n[i]='9';
                return stoi(n);
            }

        }
        return stoi(n);
        
    }
};