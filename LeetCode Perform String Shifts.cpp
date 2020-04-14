/*
You are given a string s containing lowercase English letters,
and a matrix shift, where shift[i] = [direction, amount]:
direction can be 0 (for left shift) or 1 (for right shift).
amount is the amount by which string s is to be shifted.
A left shift by 1 means remove the first character of s and append it to the end.
Similarly, a right shift by 1 means remove the last character of s
and add it to the beginning.
Return the final string after all operations.
*/

#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    string stringShift(string s, vector<vector<int>>& shift)
    {
        //Get the first amount of the shift, set it to negative if it's a left shift
        int shiftAmount=shift[0][1];
        if(shift[0][0]==0)
            shiftAmount=-shiftAmount;

        //If we get a left shift decrease the amount by which we switch, if right increase it
        int shiftSize=shift.size();
        for(int i=1; i<shiftSize; ++i)
        {
            if(shift[i][0]==0)
                shiftAmount-=shift[i][1];
            else
                shiftAmount+=shift[i][1];
        }

        //If the amount is bigger than 0 the final shift is a right shift
        if(shiftAmount>0)
        {
            shiftAmount%=s.size();
            s=s.substr(s.size()-shiftAmount)+s.substr(0, s.size()-shiftAmount);
            cout<<s<<endl;
        }

        //If the amount is less than 0 the final shift is a left shift
        else if(shiftAmount<0)
        {
            shiftAmount=-shiftAmount;
            shiftAmount%=s.size();
            s=s.substr(0+shiftAmount)+s.substr(0, shiftAmount);
        }
        return s;
    }
};
