
#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *next;

    Node(int x)
    {
        data = x;
        next = NULL;
    }
};

void print(Node *head) // Function to print the LinkedList
{
    Node *curr = head;
    for (; curr != nullptr; curr = curr->next)
        cout << curr->data << "-->";
    cout << "null" << endl;
}

int mine(Node *h1, Node *h2)
{
    unordered_set<Node *> s;
    Node *curr = h1;
    while (curr != NULL)
    {
        s.insert(curr);
        curr = curr->next;
    }
    Node *curr2 = h2;
    while (curr2 != NULL)
    {
        if (s.count(curr2))
        {
            return curr2->data;
        }
        curr2 = curr2->next;
    }
}

int efficient(Node *h1, Node *h2)
{
    Node *curr = h1;
    int c1 = 0, c2 = 0;
    while (curr != NULL)
    {
        c1++;
        curr = curr->next;
    }
    curr = h2;
    while (curr != NULL)
    {
        c2++;
        curr = curr->next;
    }
    int d = abs(c1 - c2);
    Node *curr1 = h1;
    Node *curr2 = h2;
    while (d != 0)
    {
        if (c1 > c2)
            curr1 = curr1->next;
        else
            curr2 = curr2->next;
        --d;
    }
    // cout << curr1->next->data;
    while (curr1 != NULL and curr2 != NULL)
    {
        if (curr1 == curr2)
        {
            return curr1->data;
        }
        curr1 = curr1->next;
        curr2 = curr2->next;
    }
    return -1;
}

int main()
{
    Node *h1 = new Node(5);
    h1->next = new Node(8);
    h1->next->next = new Node(7);
    h1->next->next->next = new Node(10);
    h1->next->next->next->next = new Node(12);
    h1->next->next->next->next->next = new Node(15);

    Node *temp = h1->next->next->next;
    Node *h2 = new Node(9);
    h2->next = temp;

    cout << "Before" << endl;
    print(h1);
    cout << efficient(h1, h2);
    cout << "\nAfter" << endl;
    print(h2);

    return 0;
}
