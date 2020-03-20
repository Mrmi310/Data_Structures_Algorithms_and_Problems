//Stack implementation using linked list
#include <iostream>
#include <stddef.h>

struct Node
{
    int data;
    Node* next;
};

class MyStack
{
public:
    Node* head = NULL;
    
    //Inserts an element to the top of the stack
    void push(int element)
    {
        Node* toPush = new Node();
        toPush->data=element;
        toPush->next=head;
        head=toPush;
    }

    //Deletes an element from the top of the stack
    void pop()
    {
        //Can't delete an element from an empty stack
        if(isEmpty())
        {
            std::cout<<"Pop error: Stack underflow.\n";
            return;
        }
        Node* temp;
        temp=head;
        head=head->next;
        delete temp;
    }

    //Returns the top element of the stack
    int top()
    {
        if(isEmpty())
        {
            std::cout<<"Top error: the stack is empty. - returning -1\n";
            return (int)nullptr;
        }
        return head->data;
    }

    //Checks whethever the stack is empty
    bool isEmpty()
    {
        return (head==NULL) ? true : false;
    }

    //Prints the stack
    void printStack()
    {
        Node* passer = head;
        while(passer!=NULL)
        {
            std::cout<<passer->data<<" ";
            passer=passer->next;
        }
        std::cout<<"\n";
    }
};

//Code for testing out the stack
int main()
{
    MyStack* llStack = new MyStack();
    std::cout<<llStack->top()<<"\n";
    std::cout<<llStack->isEmpty()<<"\n";
    llStack->pop();
    llStack->push(3);
    llStack->printStack();
    llStack->push(4);
    llStack->printStack();
    llStack->pop();
    llStack->printStack();
    std::cout<<llStack->top()<<"\n";
    llStack->pop();
}
