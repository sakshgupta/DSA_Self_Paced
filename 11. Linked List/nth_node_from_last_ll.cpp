
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

void mine(Node *head, int n)
{
    Node *curr = head;
    int c = 0;
    while (curr != NULL)
    {
        c++;
        curr = curr->next;
    }

    c -= n;
    if (c < 0)
        return;
    int k = 0;
    curr = head;
    while (curr != NULL and k != c)
    {
        curr = curr->next;
        k++;
    }
    cout << curr->data << endl;
}

void efficient(Node *head, int n)
{
    Node *first = head;
    Node *second = head;

    for (int i = 0; i < n; i++)
    {
        if (first == NULL)
            return;
        first = first->next;
    }
    while (first != NULL)
    {
        first = first->next;
        second = second->next;
    }
    cout << second->data << endl;
}

int main()
{
    Node *head = new Node(10);
    head->next = new Node(30);
    head->next->next = new Node(50);
    head->next->next->next = new Node(70);
    head->next->next->next->next = new Node(90);

    cout << "Before" << endl;
    print(head);
    mine(head, 2);
    cout << "\nAfter" << endl;
    print(head);

    return 0;
}
