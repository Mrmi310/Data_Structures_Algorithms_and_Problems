/*
C++ solution for https://leetcode.com/problems/middle-of-the-linked-list/submissions/
876. Middle of the Linked List
Difficulty: Easy
Runtime: 0 ms, faster than 100.00% of C++ online submissions for Middle of the Linked List.
Memory Usage: 6.4 MB, less than 100.00% of C++ online submissions for Middle of the Linked List.

Given a non-empty, singly linked list with head node head,
return a middle node of linked list.

If there are two middle nodes, return the second middle node.
*/
class Solution
{
public:
    ListNode* middleNode(ListNode* head)
    {
        unsigned short listLength=0, halfLength;
        ListNode* passer=head;
        //Calculate the length of the linked list
        while(passer!=NULL)
        {
            passer=passer->next;
            ++listLength;
        }

        //Calculate half of the length (so it doesn't get calculated every time in the for loop below)
        halfLength=listLength/2;
        if(listLength%2==1)
            ++halfLength;

        //Loop until the (first) element in the middle of the array
        passer=head;
        for(unsigned short i=1; i<halfLength; ++i)
        {
            passer=passer->next;
        }

        //If there are 2 middle elements (the array's length is divisible by 2), return the second middle element
        if(listLength%2==0)
            return passer->next;
        //Else, return the middle element
        return passer;
    }
};
