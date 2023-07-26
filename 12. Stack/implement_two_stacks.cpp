#include <bits/stdc++.h>

using namespace std;

struct mine
{
    int *arr, cap, top1, top2;
    mine(int n)
    {
        cap = n;
        top1 = -1;
        top2 = cap;
        arr = new int[cap];
    }
    void push1(int x)
    {
        if (top1 < top2 - 1)
        {
            top1++;
            arr[top1] = x;
        }
    }
    void push2(int x)
    {
        if (top1 < top2 - 1)
        {
            top2--;
            arr[top2] = x;
        }
    }
    int pop1()
    {
        if (top1 >= 0)
        {
            int x = arr[top1];
            top1--;
            return x;
        }
        else
            return -1;
    }
    int pop2()
    {
        if (top2 < cap)
        {
            int x = arr[top2];
            top2++;
            return x;
        }
        else
            return -1;
    }
};

int main()
{

    // Creating stack object with capacity of 5 elements
    mine s(5);

    // Pushing some values into both stacks
    s.push1(10);
    s.push2(20);
    s.push2(30);
    s.push1(40);
    s.push2(50);

    // Popping all values from the first stack
    cout << "Popped from stack one: " << s.pop1() << endl;
    cout << "Popped from stack one: " << s.pop1() << endl;
    cout << "Popped from stack one: " << s.pop1() << endl;

    // Popping all values from the second stack
    cout << "Popped from stack two: " << s.pop2() << endl;
    cout << "Popped from stack two: " << s.pop2() << endl;
    cout << "Popped from stack two: " << s.pop2() << endl;

    return 0;
}
