
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
}

Node *deleteStart(Node *head, int x)
{
    if (head == NULL)
        return NULL;
    head = head->next;
    return head;
}

int main()
{
    Node *head = new Node(10);
    head->next = new Node(20);
    head->next->next = new Node(30);

    cout << "Before" << endl;
    print(head);
    head = deleteStart(head, 10);
    head = deleteStart(head, 20);
    cout << "After" << endl;
    print(head);

    return 0;
}
