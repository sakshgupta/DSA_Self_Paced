
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

void mine(Node *head)
{
    if (head == NULL)
        return;
    int c = 0;
    for (Node *i = head; i != NULL; i = i->next)
    {
        c++;
    }

    c = (c / 2) + 1;
    Node *curr = head;
    int k = 1;
    while (curr != NULL and k != c)
    {
        curr = curr->next;
        k++;
    }
    cout << curr->data << endl;
}

void efficient(Node *head)
{
    if(head == NULL) return;
    Node *slow = head, *fast = head;
    while (fast != NULL and fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    cout << slow->data << endl;
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
    efficient(head);
    cout << "\nAfter" << endl;
    print(head);

    return 0;
}
