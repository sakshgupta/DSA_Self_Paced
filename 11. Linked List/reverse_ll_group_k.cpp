
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

struct Node *mine(struct Node *head, int k)
{
    Node *curr = head, *prev = NULL, *next = NULL;
    int count = 0;
    while (curr != NULL and count < k)
    {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
        ++count;
    }
    if (next != NULL)
    {
        Node *revhead = mine(next, k);
        head->next = revhead;
    }
    return prev;
}

int main()
{
    Node *head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);
    head->next->next->next->next = new Node(5);

    cout << "Before" << endl;
    print(head);
    head = mine(head, 2);
    cout << "\nAfter" << endl;
    print(head);

    return 0;
}
