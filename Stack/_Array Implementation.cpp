//Stack implementation using an array
#include <iostream>


#define maxSize 100 //The maximum size of the stack

class MyStack
{
public:
    int stackArray[maxSize]; //The array used for implementing the stack
    int topIndex = -1; //Represents the top element on the stack's index in the stack array
    
    //Inserts an element to the top of the stack
    void push(int element)
    {
        //Can't push an element into a full stack
        if(topIndex==maxSize-1)
        {
            std::cout<<"Push error: Stack overflow.\n";
            return;
        }
        stackArray[++topIndex]=element;
    }
    
    //Deletes an element from the top of the stack
    void pop()
    {
        //Can't delete an element from an empty stack
        if(topIndex==-1)
        {
            std::cout<<"Pop error: Stack underflow.\n";
            return;
        }
        else
            --topIndex;
    }
    
    //Outputs the top element of the stack
    void top()
    {
        if(topIndex==-1)
        {
            std::cout<<"Top error: the stack is empty.\n";
            return;
        }
        std::cout<<stackArray[topIndex]<<"\n";
    }
  
    //Checks whethever the stack is empty
    bool isEmpty()
    {
        return (topIndex==-1) ? true : false;
    }

    //Checks whethever the stack is full
    bool isFull()
    {
        return (topIndex==maxSize-1) ? true : false;
    }

    //Prints the stack
    void printStack()
    {
        for(int i=0; i<=topIndex; ++i)
            std::cout<<stackArray[i]<<" ";
        std::cout<<"\n";
    }
};
