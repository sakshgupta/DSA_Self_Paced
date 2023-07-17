
#include <bits/stdc++.h>
using namespace std;

#define d 256

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

void print(Node *head)
{
    while (head != NULL)
    {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

int mine(Node *head, int x)
{
    Node *curr = head;
    for (int i = 1; curr != NULL; i++)
    {
        if (curr->data == x)
            return i;
        curr = curr->next;
    }
    return -1;
}

int minerecursive(Node *head, int x, int pos)
{
    if (head == NULL)
        return -1;

    if (head->data == x)
        return pos;

    minerecursive(head->next, x, ++pos);
}

int main()
{
    Node *head = new Node(10);
    head->next = new Node(30);
    head->next->next = new Node(50);
    head->next->next->next = new Node(70);

    cout << "Before" << endl;
    print(head);
    cout << minerecursive(head, 100, 1) << endl;
    cout << "\nAfter" << endl;
    print(head);

    return 0;
}
