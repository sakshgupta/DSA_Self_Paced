#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node(int x)
    {
        data = x;
        next = nullptr;
    }
};

Node *head, *tail; // head and tail of the LinkedList

void PrintList(Node *head) // Function to print the LinkedList
{
    Node *curr = head;
    for (; curr != nullptr; curr = curr->next)
        cout << curr->data << "-->";
    cout << "null" << endl;
}

void InsertatLast(int dataue) // Function for creating a LinkedList
{
    Node *newnode = new Node(dataue);
    if (head == nullptr)
        head = newnode, tail = newnode;
    else
        tail = tail->next = newnode;
}

Node *SegregatetoOddEVen()
{
    Node *oddhead = new Node(-1), *oddtail = oddhead;
    Node *evenhead = new Node(-1), *eventail = evenhead;

    Node *curr = head;
    while (curr != NULL)
    {
        Node *temp = curr;
        curr = curr->next;
        temp->next = NULL;

        if (temp->data & 1) // if odd
        {
            oddtail->next = temp;
            oddtail = temp;
        }
        else
        {
            eventail->next = temp;
            eventail = temp;
        }
    }
    eventail->next = oddhead->next;
    return evenhead->next;
}

int main()
{
    int n = 0;
    char ch = 'y';
    while (ch == 'y')
    {
        cin >> n;
        InsertatLast(n);
        cout << "y/n: ";
        cin >> ch;
    }
    cout << "Initial LinkedList : " << endl;
    PrintList(head);
    Node *newHead = SegregatetoOddEVen();
    cout << "LinkedList After Segregration " << endl;
    PrintList(newHead);
    return 0;
}