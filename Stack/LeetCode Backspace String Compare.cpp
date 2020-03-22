/*
C++ solution for https://leetcode.com/problems/backspace-string-compare/
Runtime: 0 ms, faster than 100.00% of C++ online submissions for Backspace String Compare.
Memory Usage: 6.3 MB, less than 100.00% of C++ online submissions for Backspace String Compare.
Difficulty: easy
Given two strings S and T, return if they are equal when both
are typed into empty text editors. # means a backspace character.
*/
#include <iostream>
#include <stack>

class Solution
{
public:
    bool backspaceCompare(std::string S, std::string T)
    {
        stack<char> stackS, stackT;
        int sLen=S.length(), tLen=T.length();

        /*Push every character of both strings into their respective stacks
        pop top element if # is found*/
        for(int i=0; i<sLen; ++i)
        {
            //No need to pop an element from an empty stack
            if(!stackS.empty() && S[i]=='#')
                stackS.pop();
            else if(S[i]!='#')
                stackS.push(S[i]);
        }
        for(int i=0; i<tLen; ++i)
        {
            //No need to pop an element from an empty stack
            if(!stackT.empty() && T[i]=='#')
                stackT.pop();
            else if(T[i]!='#')
                stackT.push(T[i]);
        }

        //Start comparing the stacks from their tops.
        while(!stackS.empty() && !stackT.empty())
        {
            //If their top elements don't match, the strings are not equal
            if(stackS.top()!=stackT.top())
                return false;
            //Pop top elements in both stacks to continue comparing them
            stackS.pop();
            stackT.pop();
        }
        //If both stacks are empty (no stack has a character left in it), the strings are equal
        return (stackS.empty() && stackT.empty()) ? true : false;
    }
};
