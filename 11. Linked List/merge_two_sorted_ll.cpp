
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

Node *insertPos(Node *a, Node *b)
{
    if(a==NULL) return b;
    if(b==NULL) return a;
    Node *head, *tail;
    if (a->data < b->data)
    {
        head = tail = a;
        a = a->next;
    }
    else
    {
        head = tail = b;
        b = b->next;
    }
    while (a != NULL && b != NULL)
    {
        if (a->data < b->data)
        {
            tail->next = a;
            tail = tail->next;
            a = a->next;
        }
        else
        {
            tail->next = b;
            tail = tail->next;
            b = b->next;
        }
    }
    if(a==NULL) tail->next = b;
    else tail->next = a;
    return head;
}

int main()
{
    Node *a = new Node(10);
    a->next = new Node(20);
    a->next->next = new Node(30);
    a->next->next->next = new Node(32);
    a->next->next->next->next = new Node(33);
    a->next->next->next->next->next = new Node(50);

    Node *b = new Node(5);
    b->next = new Node(15);
    b->next->next = new Node(17);
    b->next->next->next = new Node(18);
    b->next->next->next->next = new Node(35);
    b->next->next->next->next->next = new Node(45);

    cout << "Before" << endl;
    print(a);
    print(b);
    a = insertPos(a, b);
    cout << "\nAfter" << endl;
    print(a);

    return 0;
}
