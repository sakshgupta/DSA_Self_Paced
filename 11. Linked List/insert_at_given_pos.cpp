
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

Node *insertPos(Node *head, int pos, int data)
{
    Node *temp = new Node(data);
    if (pos == 1)
    {
        temp->next = head;
        return temp;
    }
    int count = 1;
    Node *curr = head;
    while (count + 1 != pos and curr != NULL)
    {
        curr = curr->next;
        count++;
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
    head = insertPos(head, 3, 20);
    cout << "\nAfter" << endl;
    print(head);

    return 0;
}
