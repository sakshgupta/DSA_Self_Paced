
#include <bits/stdc++.h>
using namespace std;

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

void print(Node *head) // Function to print the LinkedList
{
    Node *curr = head;
    for (; curr != nullptr; curr = curr->next)
        cout << curr->data << "-->";
    cout << "null" << endl;
}

void mine(Node *head)
{
    if (head == NULL or head->next == NULL)
        return;
    Node *curr = head;
    while (curr != NULL and curr->next != NULL)
    {
        swap(curr->data, curr->next->data);
        curr = curr->next->next;
    }
}

// this function rearranges a given linked list by doing pairwise swapping
Node *efficient(Node *head)
{
    // check for empty or single node linked list
    if (head == NULL || head->next == NULL)
        return head;

    // initialize node pointers and set their values
    // 1->2->3->4->5->6
    // curr = 3
    Node *curr = head->next->next;
    // prev = 1
    Node *prev = head;
    // head = 2
    head = head->next;
    // break the first node connection
    // 2->1
    head->next = prev;

    // loop until all the nodes of the linked list are reversed
    // 2->1->3->4->5->6
    while (curr != NULL && curr->next != NULL)
    {
        // next = 5
        Node *next = curr->next->next;
        // 1->4
        prev->next = curr->next;
        // prev = 3
        prev = curr;
        // 4->3
        curr->next->next = curr;
        // curr = 5
        curr = next;
    }

    // ensure that the last node is correctly linked in case of odd node count
    // 5->null
    prev->next = curr;

    return head;
}

int main()
{
    Node *head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);
    head->next->next->next->next = new Node(5);

    cout << "Before" << endl;
    print(head);
    head = efficient(head);
    cout << "\nAfter" << endl;
    print(head);

    return 0;
}
