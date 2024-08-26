//Time : 0ms BEATS : 100 %
class Solution {
public:
    string defangIPaddr(string address) {
        string ansadd = "";
        for(char &ch : address)
        {
            if(ch != '.') ansadd+=ch;
            else
            {
                ansadd+='[';
                ansadd+='.';
                ansadd+=']';
            }
        }
        return ansadd;
        
    }
};
