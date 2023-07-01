
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
    Node *curr = head;
    do
    {
        cout << curr->data << " ";
        curr = curr->next;
    } while (curr != head);
    cout << endl;
}

Node *mine(Node *head, int x)
{
    Node *temp = new Node(x);
    if (head == NULL)
    {
        temp->next = temp;
        return temp;
    }
    Node *curr = head;
    while (curr->next != head)
    {
        curr = curr->next;
    }
    curr->next = temp;
    temp->next = head;
    return temp;
}

// one way to do it in o(1) is to use tail pointer
// another way to do it in o(1) without tail pointer

// Function to add a node with given data x in the beginning of a Circular Linked List (CLL)
Node *o1(Node *head, int x)
{
    // Allocate memory for a new node
    Node *temp = new Node(x);

    // If list is empty, then make the new node  head
    if (head == NULL)
    {
        temp->next = temp;
        return temp;
    }

    // Make the new node point to the head's next of the list
    temp->next = head->next;

    // Update the link of head node to point to the new node
    head->next = temp;

    // Swap the data of the head node and the new node
    swap(head->data, temp->data);

    // Return new head of the list
    return head;
}

int main()
{
    Node *head = new Node(10);
    Node *temp1 = new Node(20);
    Node *temp2 = new Node(30);

    head->next = temp1;
    temp1->next = temp2;
    temp2->next = head;

    cout << "Before" << endl;
    print(head);
    head = o1(head, 15);
    cout << "\nAfter" << endl;
    print(head);

    return 0;
}
