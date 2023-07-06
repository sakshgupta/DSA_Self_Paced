
#include <bits/stdc++.h>
using namespace std;

#define d 256

struct Node
{
    int data;
    Node *next;
    Node *prev;

    Node(int x)
    {
        data = x;
        next = NULL;
        prev = NULL;
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

// This function traverses a given linked list 'head'
// and returns the last node without changing any of
// the nodes in the linked list.
Node *mine(Node *head)
{
    if(head == NULL or head->next == NULL) return head;
    // Reverse linked list starting at
    // last node and ending with the head
    Node *curr = head, *temp = NULL;
    while (curr != NULL)
    {
        // Swap curr->next and curr->prev
        temp = curr->prev;
        curr->prev = curr->next;
        curr->next = temp;
        // Move to next node
        curr = curr->prev;
    }

    // Return last element of reversed linked list
    return temp->prev;
}

int main()
{
    Node *head = new Node(10);
    Node *temp1 = new Node(20);
    Node *temp2 = new Node(30);

    head->next = temp1;
    temp1->next = temp2;
    temp1->prev = head;
    temp2->prev = temp1;

    cout << "Before" << endl;
    print(head);
    head = mine(head);
    cout << "\nAfter" << endl;
    print(head);

    return 0;
}
