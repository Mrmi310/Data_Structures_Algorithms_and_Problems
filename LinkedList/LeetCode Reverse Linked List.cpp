/*
C++ iterative and recursive solution for https://leetcode.com/problems/reverse-linked-list/submissions/
Possibly not quite the best solutions.
Iteratively: 
Runtime: 8 ms, faster than 94.31% of C++ online submissions for Reverse Linked List.
Memory Usage: 7.7 MB, less than 100.00% of C++ online submissions for Reverse Linked List.

Recursively: 
Runtime: 12 ms, faster than 40.51% of C++ online submissions for Reverse Linked List.
Memory Usage: 7.6 MB, less than 100.00% of C++ online submissions for Reverse Linked List.

206. Reverse Linked List
Difficulty: Easy

Reverse a singly linked list.
*/
class Solution
{
public:

    //Iterative implementation  
    ListNode* reverseList(ListNode* head)
    {
        ListNode *previous=nullptr, *current=head, *next;
        //Go through the whole list
        while(current!=nullptr)
        {
            next=current->next; //Remember the current next element
            current->next=previous; //Link of the current element to the previous element
            previous=current; //Set the previous element to the current one
            current=next; //Continue looping through the list by going to the next element
        }
        head=previous; //When current gets to null, set head to its previous element
        return head;
    }
 
    //Recursive implementation
    void reverseRecursively(ListNode* current, ListNode** head)
    {
        if(current==nullptr) //End of recursion
            return;
        if(current->next==nullptr) //Got to the last element in the list, it is the new head
        {
            *head=current;
            return;
        }
        reverseRecursively(current->next, &head); //Go deeper into the recursion
        current->next->next=current; //Link the next element to the current one
        current->next=nullptr; //Break the link to the next element
    }
    ListNode* reverseListRecursively(ListNode* head)
    {
        reverseRecursively(head, &head);
        return head;
    }
};
