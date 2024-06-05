// implement a data structure such that its class has two stacks implemented within a single array
// just implement POP and PUSH functionalities

#include <iostream>
using namespace std;

class TwoStacks
{
private:
    // properties:

    // pointer to the array:
    int *arr;
    // size of the array:
    int size;
    // top of first stack:
    int top1;
    // top of second stack:
    int top2;

public:
    // constructor:
    TwoStacks(int size)
    {
        arr = new int[size];
        this->size = size;
        top1 = -1;
        top2 = size;
    }

    // adding element to first stack:
    void push1(int element)
    {
        // check there is empty space available:
        if (top2 - top1 >= 2)
        {
            top1++;
            arr[top1] = element;
        }
        else
        {
            cout << "stack overflow" << endl;
        }
    }

    // adding element to second stack:
    void push2(int element)
    {
        // check there is empty space available:
        if (top2 - top1 >= 2)
        {
            top2--;
            arr[top2] = element;
        }
        else
        {
            cout << "stack overflow" << endl;
        }
    }

    // removing top from first stack:
    void pop1()
    {
        // check the stack1 should not be empty:
        if (top1 >= 0)
        {
            top1--;
        }
        else
        {
            cout << "Stack1 empty" << endl;
        }
    }

    // removing top from second stack:
    void pop1()
    {
        // check the stack1 should not be empty:
        if (top2 < size)
        {
            top2++;
        }
        else
        {
            cout << "Stack2 empty" << endl;
        }
    }
};

int main() {}