/*
https://leetcode.com/problems/palindrome-linked-list/
234. Palindrome Linked List
Difficulty: Easy
Runtime: 8 ms, faster than 99.98% of C++ online submissions for Palindrome Linked List.
Memory Usage: 11 MB, less than 100.00% of C++ online submissions for Palindrome Linked List.
Inefficent solution: O(n) time complexity and O(n) space complexity

Given a singly linked list, determine if it is a palindrome.
*/
#include <stack>
using namespace std;
class Solution
{
public:
    bool isPalindrome(ListNode* head)
    {
        iostream::sync_with_stdio(false); //Speeds up lots input by a lot ;)
        
        stack<int> dataStack; //A stack to hold all elements of the list
        ListNode* current=head;

        //Pushing the elements of the list into the stack
        while(current!=nullptr)
        {
            dataStack.push(current->val);
            current=current->next;
        }
        current = head;
        //Comparing the top elements of the stack to the elements of the list starting from the head
        while(!dataStack.empty())
        {
            //If their values aren't equal, the list isn't a palindrome
            if(dataStack.top()!=current->val)
                return false;

            //Pop the top element and traverse the list further to continue checking if the list is a palindrome
            dataStack.pop();
            current=current->next;
        }
        //If the stack gets empty return true - the list is a palindrome
        return true;
    }
};
