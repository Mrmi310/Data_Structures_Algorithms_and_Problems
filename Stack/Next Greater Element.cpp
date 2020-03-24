/*
Given an array of size n, find the next greater element of each element in the array.
The next greater element is the first element whose value and index in the array is bigger.
If an element in the array doesn't have a next greater element, output -1.
Example:
Input: 5, 7, 2, 33
      Input   Next greater element
        5   ->     7
        7   ->    33
        2   ->    33
        33  ->    -1
Time complexity: O(n)
Space complexity: O(n)
*/
#include <iostream>
#include <stack>
using namespace std;

void nextGreater(int a[], int n)
{
    stack <int> intStack;
    int output[n];

    //Traverse the array from right to left (the current element will already have its next greater element in the stack)
    for(int i=n-1; i>-1; --i)
    {
        //Pop the top element of the stack until either a bigger element than a[i] is found in the stack or the stack is empty
        while(!intStack.empty() && intStack.top()<=a[i])
            intStack.pop();
        if(intStack.empty()) //If the stack gets emptied, the current element in the array has no next greater element
            output[i]=-1;
        else //If it's not empty, the next greater element for the current element in the array is on the top of the stack
            output[i]=intStack.top();

        intStack.push(a[i]); //Push the current element to the stack for further comparison
    }

    //Output elements in the array and their next greater elements in the array
    for(int i=0; i<n; ++i) 
        cout<<a[i]<<"->"<<output[i]<<"\n";
}
int main()
{
    iostream::sync_with_stdio(false);
    int n;
    cin>>n;
    int a[n];
    for(int i=0; i<n; ++i)
        cin>>a[i];
    nextGreater(a, n);
    return 0;
}
