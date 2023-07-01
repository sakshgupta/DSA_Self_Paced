// C++ code to implement the approach

#include <bits/stdc++.h>
using namespace std;

// Structure of a node of linked list
struct Node
{
    int val;
    Node *next;
    Node *arbit;

    // Constructor
    Node(int x)
    {
        this->val = x;
        this->next = NULL;
        this->arbit = NULL;
    }
};

// Function to clone the linked list
Node *cloneLinkedList(Node *head)
{
    // This unordered map maps each node in the original linked list with its corresponding new node in the cloned list.
    unordered_map<Node *, Node *> hm;

    // The for loop goes through each node, creates a new node with the value of the current node and adds it to the unordered map.
    for (Node *curr = head; curr != NULL; curr = curr->next)
    {
        hm[curr] = new Node(curr->val);
    }

    Node *clonecurr;
    // The second for loop updates the next and arbitrary pointer of each node in the cloned linked list by getting their pointers from the unordered map.
    for (Node *curr = head; curr != NULL; curr = curr->next)
    {
        clonecurr = hm[curr];
        clonecurr->next = hm[curr->next];
        clonecurr->arbit = hm[curr->arbit];
    }

    // the pointer to the head of the cloned linked list is returned.
    return hm[head];
}

// function takes a pointer to a Node as an argument
// and returns a cloned linked list pointer
Node *efficient(Node *head)
{
    // iterate through list and create cloned nodes for each original node
    for (Node *curr = head; curr != NULL;)
    {
        Node *next = curr->next; // store reference to next node
        curr->next = new Node(curr->val); // insert cloned node after current node
        curr->next->next = next; // attach stored next node to cloned node
        curr = next; // go to the next node
    }

    // iterate thought list, setting arbit pointer of cloned node to next of arbit of original node
    for (Node *curr = head; curr != NULL; curr = curr->next->next)
    {
        curr->next->arbit = (curr->arbit != NULL) ? curr->arbit->next : NULL;
    }

    // assign pointers to the original list and cloned list
    Node *original = head;
    Node *copied = head->next;

    // store reference to head of cloned list
    Node *temp = copied;

    // separate original list and cloned list
    while (original and copied)
    {
        // skip every other node
        original->next = (original->next) ? original->next->next : original->next;
        copied->next = (copied->next) ? copied->next->next : copied->next;

        // move to the next node
        original = original->next;
        copied = copied->next;
    }

    return temp; // return the head of the cloned list
}

// Function to print the linked list
void printList(Node *head)
{
    cout << head->val << "(" << head->arbit->val << ")";
    head = head->next;
    while (head != NULL)
    {
        cout << " -> " << head->val << "(" << head->arbit->val << ")";
        head = head->next;
    }
    cout << endl;
}

int main()
{
    // Creating a linked list with random pointer
    Node *head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);
    head->next->next->next->next = new Node(5);
    head->arbit = head->next->next;
    head->next->arbit = head;
    head->next->next->arbit = head->next->next->next->next;
    head->next->next->next->arbit = head->next->next;
    head->next->next->next->next->arbit = head->next;

    cout << "The original linked list:\n";
    printList(head);

    Node *sol = efficient(head);

    cout << "The cloned linked list:\n";
    printList(sol);

    return 0;
}
