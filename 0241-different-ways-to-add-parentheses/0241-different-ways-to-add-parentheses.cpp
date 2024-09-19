class Solution {
public:
    vector<int> solve(string expression) {
        vector<int> result;
        for (int i = 0; i < expression.length(); i++) {
            if (expression[i] == '+' || expression[i] == '-' || expression[i] == '*')
            {
                vector<int> leftResults = solve(expression.substr(0, i));
                vector<int> rightResults= solve(expression.substr(i + 1));
                for (int& x : leftResults)
                {
                    for (int& y : rightResults)
                    {
                        if(expression[i] == '+')
                        {
                            result.push_back(x+y);
                        }
                        else if(expression[i] == '*')
                        {
                            result.push_back(x*y);
                        } else
                        {
                            result.push_back(x - y);
                        }
                    }
                }
            }
        }
        if (result.empty())
        {
            result.push_back(stoi(expression));
        }
        return result;
    }
    vector<int> diffWaysToCompute(string expression) {
        return solve(expression);
    }
};