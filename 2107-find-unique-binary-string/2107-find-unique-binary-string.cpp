class Solution {
public:
    void solve(string& temp, int n, string& result, unordered_set<string>& st,
               bool& found) {
        if (temp.length() == n) {
            if (st.find(temp) == st.end()) {
                result += temp;
                found = true;
            }
            return;
        }
        if (found == true) {
            return;
        }

        temp.push_back('0');
        solve(temp, n, result, st, found);
        temp.pop_back();
        if (found == true) {
            return;
        }
        temp.push_back('1');
        solve(temp, n, result, st, found);
        temp.pop_back();
    }
    string findDifferentBinaryString(vector<string>& nums) {
        int n = nums.size();
        string temp = "";
        string result = "";
        bool found = false;
        unordered_set<string> st(begin(nums), end(nums));
        solve(temp, n, result, st, found);
        return result;
    }
};