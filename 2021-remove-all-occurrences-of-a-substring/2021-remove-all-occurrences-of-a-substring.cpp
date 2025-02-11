class Solution {
public:
    string removeOccurrences(string s, string part) {
        int n = part.length();
        while(s.find(part) != string::npos){
            int index = s.find(part);
            s.erase(index,n);
        }
        return s; 
    }
};