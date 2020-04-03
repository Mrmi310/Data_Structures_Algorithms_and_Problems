/*
https://leetcode.com/problems/decrypt-string-from-alphabet-to-integer-mapping/submissions/
iven a string s formed by digits ('0' - '9') and '#' . We want to map s to English lowercase characters as follows:

    Characters ('a' to 'i') are represented by ('1' to '9') respectively.
    Characters ('j' to 'z') are represented by ('10#' to '26#') respectively.

Return the string formed after mapping.

It's guaranteed that a unique mapping will always exist.
Difficulty: Easy
Runtime: 0 ms, faster than 100.00% of C++ online submissions for Decrypt String from Alphabet to Integer Mapping.
Memory Usage: 6.5 MB, less than 100.00% of C++ online submissions for Decrypt String from Alphabet to Integer Mapping.
*/
#include <iostream>
#include <string>
using namespace std;
class Solution
{
public:

    int findCode(string codes[], string s)
    {
        for(int i=0; i<26; ++i)
        {
            if(s==codes[i])
                return i;
        }
        return -1;
    }
    string freqAlphabets(string s)
    {
        iostream::sync_with_stdio(false);
        cin.tie(0);
        string alphabet[26]= {"a", "b", "c", "d", "e", "f", "g", "h", "i", "j", "k", "l", "m",
                              "n", "o", "p", "q", "r", "s", "t", "u", "v", "w", "x", "y", "z"
                             };
        string codes[26]= {"1", "2", "3", "4", "5", "6", "7", "8", "9", "10#", "11#", "12#", "13#",
                           "14#", "15#", "16#", "17#", "18#", "19#", "20#", "21#",
                           "22#", "23#", "24#", "25#", "26#"
                          };
        string decoded="", temp;
        int sLen=s.length();
        for(int i=0; i<sLen; ++i)
        {
            temp="";
            if(i+2<sLen && s[i+2]=='#')
            {
                temp=temp+s[i]+s[i+1]+s[i+2];
                //cout<<"t: "<<temp<<"\n";
                decoded+=alphabet[findCode(codes, temp)];
                i+=2;
            }
            else
            {
                temp=s[i];
                for(int j=0; j<10; ++j)
                {
                    if(temp==codes[j])
                        decoded+=alphabet[j];
                }
            }
        }
        return decoded;
    }
};
