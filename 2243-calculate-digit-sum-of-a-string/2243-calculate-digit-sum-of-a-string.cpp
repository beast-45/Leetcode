class Solution {
public:
    string digitSum(string s, int k) {
        string temp = s;
        while(temp.length() > k){
            string ns = "";
            int n = temp.length();
            for(int i=0 ; i<n ; i+=k){
                int sum = 0;
                for(int j=i ; j<min(n,i+k) ; j++) sum += temp[j]-'0';
                ns += to_string(sum);
            }
            temp = ns;
        }
        return temp;
    }
};