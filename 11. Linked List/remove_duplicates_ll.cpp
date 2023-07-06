
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
    Node *curr = head;
    while (curr != NULL and curr->next != NULL)
    {
        if (curr->data == curr->next->data)
        {
            Node *temp = curr->next;
            curr->next = curr->next->next;
            delete temp;
        }
        else
            curr = curr->next;
    }
}

int main()
{
    Node *head = new Node(10);
    head->next = new Node(20);
    head->next->next = new Node(20);
    head->next->next->next = new Node(20);
    head->next->next->next->next = new Node(30);
    head->next->next->next->next->next = new Node(30);

    cout << "Before" << endl;
    print(head);
    mine(head);
    cout << "\nAfter" << endl;
    print(head);

    return 0;
}
