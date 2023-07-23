// C++ program to implement a stack that supports
// getMinimum() in O(1) time and O(1) extra space.
#include <bits/stdc++.h>
using namespace std;

// A user defined stack that supports getMin() in
// addition to push() and pop()
struct MyStack
{
    stack<int> s;
    int minel;

    MyStack()
    {
        minel = INT_MAX;
    }

    void push(int x)
    {
        if (s.empty())
        {
            minel = x;
            s.push(x);
        }
        else
        {
            if (x < minel)
            {
                s.push(2 * x - minel);
                minel = x;
            }
            else
            {
                s.push(x);
            }
        }
        cout << "Number inserted: " << x << endl;
    }

    void pop()
    {
        if (s.empty())
            return;
        int temp = s.top();
        if (temp <= minEle)
        {
            s.pop();
            int temp2 = minEle;
            minEle = 2 * minEle - temp;
            cout << temp2 << endl;
        }
        else
        {
            s.pop();
            cout << temp << endl;
        }
    }

    void getMin()
    {
        cout << "Minimum element: " << minel << endl;
    }
};

// Driver Code
int main()
{
    MyStack s;

    // Function calls
    s.push(3);
    s.push(5);
    s.getMin();
    s.push(2);
    s.push(1);
    s.getMin();
    s.pop();
    s.getMin();
    s.pop();
    // s.peek();

    return 0;
}
