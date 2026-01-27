#include <iostream>
#include <vector>
#include <string>
#include <map>
using namespace std;

class Solution
{
public:
    map<string, vector<int>> m;
    vector<int> diffWaysToCompute(string expression)
    {
        vector<int> res;
        if (m.count(expression))
            return m[expression];
        int n = expression.size();
        int c = 0;
        for (char i : expression)
        {
            if (i == '+' || i == '-' || i == '*')
                c++;
        }
        if (c == 0)
        {
            int num = stoi(expression);
            res.push_back(num);
            return res;
        }
        for (int i = 0; i < n; i++)
        {
            char ch = expression[i];
            if (ch == '+' || ch == '-' || ch == '*')
            {
                vector<int> left = diffWaysToCompute(expression.substr(0, i));
                vector<int> right =
                    diffWaysToCompute(expression.substr(i + 1, n));
                for (int x : left)
                {
                    for (int y : right)
                    {
                        switch (ch)
                        {
                        case '+':
                            res.push_back(x + y);
                            break;
                        case '-':
                            res.push_back(x - y);
                            break;
                        case '*':
                            res.push_back(x * y);
                            break;
                        }
                    }
                }
            }
        }
        m.insert({expression, res});
        return res;
    }
};