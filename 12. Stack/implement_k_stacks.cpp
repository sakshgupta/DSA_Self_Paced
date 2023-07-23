#include <iostream>
using namespace std;

class mine
{
public:
    int *arr;
    int *top;
    int *next;

    int n, s;

    int freespot;
    // Initialize your data structure.
    mine(int N, int S)
    {
        n = N;
        s = S;
        arr = new int[s];
        top = new int[n];
        next = new int[s];

        // top initialise
        for (int i = 0; i < n; i++)
        {
            top[i] = -1;
        }

        // next initialise
        for (int i = 0; i < s; i++)
        {
            next[i] = i + 1;
        }
        // update last index value to -1
        next[s - 1] = -1;

        // initialise freespot
        freespot = 0;
    }

    // Pushes 'X' into the Mth stack. Returns true if it gets pushed into the stack, and false otherwise.
    bool push(int x, int m)
    {
        // check for overflow
        if (freespot == -1)
        {
            return false;
        }

        // find index
        int index = freespot;

        // insert element into array
        arr[index] = x;

        // update freespot
        freespot = next[index];

        // update next;
        next[index] = top[m - 1];

        // update top
        top[m - 1] = index;

        return true;
    }

    // Pops top element from Mth Stack. Returns -1 if the stack is empty, otherwise returns the popped element.
    int pop(int m)
    {
        // check underflow condition
        if (top[m - 1] == -1)
        {
            return -1;
        }

        int index = top[m - 1];

        top[m - 1] = next[index];

        next[index] = freespot;

        freespot = index;

        return arr[index];
    }
};

int main()
{
    int n = 3; // number of stacks
    int s = 6; // size of array

    mine myStack(n, s);

    myStack.push(5, 1);  // push 5 into 1st stack
    myStack.push(10, 2); // push 10 into 2nd stack
    myStack.push(15, 3); // push 15 into 3rd stack

    // print array before popping
    cout << "Array before popping: ";
    for (int i = 0; i < s; i++)
    {
        cout << myStack.arr[i] << " ";
    }
    cout << endl;

    int poppedElement = myStack.pop(2); // pop element from 2nd stack
    if (poppedElement != -1)            // if stack is not empty
    {
        cout << "Popped element: " << poppedElement << endl;
    }

    myStack.push(20, 1); // push 20 into 1st stack

    // print array after pushing
    cout << "Array after pushing: ";
    for (int i = 0; i < s; i++)
    {
        cout << myStack.arr[i] << " ";
    }
    cout << endl;

    return 0;
}