
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

// int x = 100;
Node *mine(Node *head, int x)
{
    Node *curr = head;
    Node *temp = new Node(x);
    if (head == NULL)
        return temp;
    if (curr->data > x)
    {
        temp->next = curr;
        return temp;
    }
    while (curr->next != NULL and curr->next->data < x)
    {
        curr = curr->next;
    }
    temp->next = curr->next;
    curr->next = temp;
    return head;
}

int main()
{
    Node *head = new Node(10);
    head->next = new Node(30);
    head->next->next = new Node(50);
    head->next->next->next = new Node(70);

    cout << "Before" << endl;
    print(head);
    head = mine(head, 140);
    cout << "\nAfter" << endl;
    print(head);

    return 0;
}
