/*
LeetCode problem https://leetcode.com/problems/valid-parentheses/ solved in C++
Difficulty: easy

Given a string containing just the characters
'(', ')', '{', '}', '[' and ']', determine if the input string is valid.

An input string is valid if:

    Open brackets must be closed by the same type of brackets.
    Open brackets must be closed in the correct order.

Note that an empty string is also considered valid.
*/
#include <iostream>
#include <string>
#include <stack>
using namespace std;
class Solution
{
public:
    bool isValid(string s)
    {
        if(s=="")
            return true;
        stack<char> charStack;
        int stringSize=s.size();
        for(int i=0; i<stringSize; ++i)
        {
            char c=s[i];
            if(c=='(' || c=='[' || c=='{')
            {
                charStack.push(c);
            }
            else
            {
                if(c==')')
                {
                    if(!charStack.empty() && charStack.top()=='(')
                        charStack.pop();
                    else
                        return false;
                }
                else if(c==']')
                {
                    if(!charStack.empty() && charStack.top()=='[')
                        charStack.pop();
                    else
                        return false;
                }
                else if(c=='}')
                {
                    if(!charStack.empty() && charStack.top()=='{')
                        charStack.pop();
                    else
                        return false;
                }
            }
        }
        return charStack.empty();
    }
};
