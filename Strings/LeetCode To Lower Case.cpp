/*
Implement function ToLowerCase() that has a string parameter str, and returns the same string in lowercase.
Difficulty: Easy
Runtime: 0 ms, faster than 100.00% of C++ online submissions for To Lower Case.
Memory Usage: 6.3 MB, less than 100.00% of C++ online submissions for To Lower Case.
*/
class Solution
{
public:
    string toLowerCase(string str)
    {
        iostream::sync_with_stdio(false);
        cin.tie(0);
        int i,strLen=str.length(), found;
        string lowerCase="abcdefghijklmnopqrstuvwxyz";
        string upperCase="ABCDEFGHIJKLMNOPQRSTUVWXYZ";
        for(i=0; i<strLen; ++i)
        {
            found=upperCase.find(str[i]);
            if(found>-1)
            {
                str[i]=lowerCase[found]; //ascii difference between upper and its lower case character is 27
            }
        }
        return str;
    }
};
