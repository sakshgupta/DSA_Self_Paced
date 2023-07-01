
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

bool method3(Node *head)
{
    node *temp = new Node;
    Node *curr = head;

    while (curr != NULL)
    {
        if (curr->next == NULL)
            return false;
        if (curr->next == temp)
            return true;
        Node *next = curr->next;
        curr->next = temp;
        curr = next;
    }
    return false;
}

int main()
{
    Node *head = new Node(10);
    head->next = new Node(20);
    head->next->next = new Node(20);
    Node *temp = head->next->next;
    head->next->next->next = new Node(20);
    head->next->next->next->next = new Node(30);
    head->next->next->next->next->next = temp;

    cout << "Before" << endl;
    // print(head);
    cout << method3(head);
    cout << "\nAfter" << endl;
    // print(head);

    return 0;
}
