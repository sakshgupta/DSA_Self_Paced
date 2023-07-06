
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

Node *reverseList(Node *head)
{
    Node *curr = head;
    Node *prev = NULL;

    while (curr != NULL)
    {
        Node *next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    return prev;
}

bool mine(Node *head)
{
    if (head == NULL or head->next == NULL)
        return true;
    Node *slow = head, *fast = head;
    while (fast->next != NULL and fast->next->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    cout << slow->data << endl;
    Node *rev = reverseList(slow->next);
    Node *curr = head;
    while (rev != NULL)
    {
        if (rev->data != curr->data)
        {
            slow->next = reverseList(slow->next);
            return false;
        }
        rev = rev->next;
        curr = curr->next;
    }
    slow->next = reverseList(slow->next);
    return true;
}

int main()
{
    Node *head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);

    cout << "Before" << endl;
    print(head);
    cout << mine(head);
    cout << "\nAfter" << endl;
    print(head);

    return 0;
}
