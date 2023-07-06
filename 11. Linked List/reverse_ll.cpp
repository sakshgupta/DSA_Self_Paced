
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

Node *mine(Node *head)
{
    Node *curr = head->next;
    Node *prev = head;

    prev->next = NULL;

    while (curr != NULL)
    {
        Node *next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    return prev;
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
    head = mine(head);
    cout << "\nAfter" << endl;
    print(head);

    return 0;
}
