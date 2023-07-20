
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

// this trick doen't work with last node
void mine(Node *curr)
{
    curr->data = curr->next->data;
    delete (curr->next);
    curr->next = NULL;
}

int main()
{
    Node *head = new Node(10);
    head->next = new Node(30);
    head->next->next = new Node(50);
    head->next->next->next = new Node(70);

    cout << "Before" << endl;
    print(head);
    mine(head->next->next->next);
    cout << "\nAfter" << endl;
    print(head);

    return 0;
}
