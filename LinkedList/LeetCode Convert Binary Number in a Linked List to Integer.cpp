/*
https://leetcode.com/problems/convert-binary-number-in-a-linked-list-to-integer/
1290. Convert Binary Number in a Linked List to Integer
Difficulty: easy

Given head which is a reference node to a singly-linked list.
The value of each node in the linked list is either 0 or 1.
The linked list holds the binary representation of a number.

Return the decimal value of the number in the linked list.
*/
#include <stddef.h>
#include <cmath>
class Solution
{
public:
    int getDecimalValue(ListNode* head)
    {
        //Go through the entire linked list and incremenet index for each element of the list
        int index=-1, result=0;
        ListNode* passer=head;
        while(passer!=NULL)
        {
            passer=passer->next;
            ++index;
        }
        
        /*Starting to the head of the list, go through the list and if the value in the list is 1,
        add 2 to the power of index (the head element's index is the length of the list, the last
        element's index is 0)
        */
        while(index>-1)
        {
            if(head->val==1)
            {
                result+=std::pow(2, index);
            }
            head=head->next;
            --index;
        }
        return result;
    }
};
