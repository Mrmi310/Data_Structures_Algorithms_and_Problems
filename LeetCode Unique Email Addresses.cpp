/*
929. Unique Email Addresses
Difficulty: Easy

Every email consists of a local name and a domain name, separated by the @ sign.
For example, in alice@leetcode.com, alice is the local name, and leetcode.com is the domain name.
Besides lowercase letters, these emails may contain '.'s or '+'s.
If you add periods ('.') between some characters in the local name part of an email address,
mail sent there will be forwarded to the same address without dots in the local name.
For example, "alice.z@leetcode.com" and "alicez@leetcode.com" forward to the same email address.  (Note that this rule does not apply for domain names.)
If you add a plus ('+') in the local name, everything after the first plus sign will be ignored.
This allows certain emails to be filtered, for example m.y+name@email.com will be forwarded to my@email.com.  (Again, this rule does not apply for domain names.)
It is possible to use both of these rules at the same time.
Given a list of emails, we send one email to each address in the list.  How many different addresses actually receive mails?

Runtime: 24 ms, faster than 97.21% of C++ online submissions for Unique Email Addresses.
Memory Usage: 11.9 MB, less than 90.48% of C++ online submissions for Unique Email Addresses.
*/
class Solution
{
public:
    //Clean up the string using the given rules
    string cleanup(string s)
    {
        int sLen=s.length();
        int atSign = s.find('@');
        string newS="";
        for(int i=0; i<atSign; ++i)
        {
            if(s[i]=='+')
                break;
            if(s[i]!='.')
                newS+=s[i];
        }

        newS+=s.substr(atSign);
        return newS;
    }
    int numUniqueEmails(vector<string>& emails)
    {
        iostream::sync_with_stdio(false);
        cin.tie(0);
        unordered_set<string> sSet;
        //Insert all of the cleaned up strings into an unordered set
        for(string s : emails)
        {
            s=cleanup(s);
            sSet.insert(s);
        }
        //Output the size of the unordered set (all elements in a set are unique)
        return sSet.size();
    }
};
