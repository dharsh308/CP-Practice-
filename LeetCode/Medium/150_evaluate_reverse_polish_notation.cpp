#include <iostream>
#include <vector>
#include<stack>
using namespace std;

class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int>s;
        for(string i:tokens){
            if(i=="*"||i=="/"||i=="-"||i=="+"){
                int b=s.top();
                s.pop();
                int a=s.top();
                s.pop();
                if(i=="+")s.push(a+b);
                else if(i=="*")s.push(a*b);
                if(i=="-")s.push(a-b);
                if(i=="/")s.push(a/b);
            }
            else{
                s.push(stoi(i));
            }
        }
        return s.top();
    }
};