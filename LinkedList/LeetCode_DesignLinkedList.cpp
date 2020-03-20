#include <stddef.h>
//Including stddef.h for the NULL value

struct Node
{
    int data;
    Node* next;
};

class MyLinkedList
{
public:
    /** Initialize your data structure here. */
    int length;
    Node* head;
    MyLinkedList()
    {
        head=NULL;
        length=0;
    }
    /** Get the value of the index-th node in the linked list. If the index is invalid, return -1. */
    int get(int index)
    {
        //Edge cases
        if(length==0)
            return -1;
        if(index<0)
            return -1;
        if(index>=length)
            return -1;

        //Accessing head element
        if(index==0)
        {
            return head->data;
        }

        //Accessing other elements - passing through the array index-1 times
        Node* passer=head;
        for(int i=0; i<index; ++i)
        {
            passer=passer->next;
        }
        return passer->data;
    }
    /** Add a node of value val before the first element of the linked list. After the insertion, the new node will be the first node of the linked list. */
    void addAtHead(int val)
    {
        Node* toInsert = new Node();
        toInsert->data=val;

        if(length==0) //In case there's no head element (the list is empty)
            toInsert->next=NULL;
        else
            toInsert->next=head;
        head=toInsert;
        ++length;
    }

    /** Append a node of value val to the last element of the linked list. */
    void addAtTail(int val)
    {
        Node* toInsert = new Node();
        toInsert->data=val;
        toInsert->next=NULL;

        if(head==NULL)
            head=toInsert;

        if(length==0) //If the list is empty, just set the head to the new element we're inserting.
        {
            head=toInsert;
            ++length;
            return;
        }
        Node* passer=head; //passes through the linked list to find the element who's next field points to NULL
        while(passer->next!=NULL)
            passer=passer->next;
        passer->next=toInsert;
        ++length;
    }

    /** Add a node of value val before the index-th node in the linked list. If index equals to the length of linked list, the node will be appended to the end of linked list. If index is greater than the length, the node will not be inserted. */
    void addAtIndex(int index, int val)
    {
        //Edge cases
        if(index<0)
            return;
        if(index>length)
            return;
        if(length==0 && index>0)
            return;
        if(index==length)
        {
            addAtTail(val);
            return;
        }
        if(index==0 || length==0)
        {
            addAtHead(val);
            return;
        }

        Node* toInsert = new Node();
        toInsert->data=val;
        Node* passer=head;
        Node* previous=head;

        for(int i=0; i<index; ++i)
        {
            previous=passer;
            passer=passer->next;
        }
        toInsert->next=passer;
        previous->next=toInsert;
        ++length;
    }
    /** Delete the index-th node in the linked list, if the index is valid. */
    void deleteAtIndex(int index)
    {
        if(index<0)
            return;
        if(index>=length)
            return;
        if(length==0)
            return;

        //Deleting the first element
        if(index==0 || length==1)
        {
            head=head->next;
            --length;
            return;
        }


        Node* passer = head;
        Node* previous = head;
        //Deleting the last element
        if(index==length-1)
        {

            while(passer->next!=NULL)
            {
                previous=passer;
                passer=passer->next;
            }
            previous->next=NULL;
            --length;
            return;
        }

        //Deleting elements between the first and the last element
        for(int i=0; i<index; ++i)
        {
            previous=passer;
            passer=passer->next;
        }
        previous->next=passer->next;
        --length;
    }
};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */
