
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

Node *mine(Node *head, int k)
{
    if (head == NULL)
        return head;
    if (head->next == head)
    {
        delete head;
        return NULL;
    }

    if (k == 1)
    {
        Node *temp = head->next;
        head->data = head->next->data;
        head->next = head->next->next;
        delete temp;
        return head;
    }

    int count = 1;
    Node *curr = head;
    while (count != k - 1)
    {
        curr = curr->next;
        count++;
    }
    Node *temp = curr->next;
    curr->next = curr->next->next;
    delete temp;
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
    head = mine(head, 3);
    cout << "\nAfter" << endl;
    print(head);

    return 0;
}
