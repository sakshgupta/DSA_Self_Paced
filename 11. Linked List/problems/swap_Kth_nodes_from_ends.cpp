//{ Driver Code Starts
#include <iostream>

using namespace std;

struct Node
{
    int data;
    struct Node *next;
    Node(int x)
    {
        data = x;
        next = NULL;
    }
};

Node *swapkthnode(Node *head, int num, int K);

void addressstore(Node **arr, Node *head)
{
    Node *temp = head;
    int i = 0;
    while (temp)
    {
        arr[i] = temp;
        i++;
        temp = temp->next;
    }
}

bool check(Node **before, Node **after, int num, int K)
{
    if (K > num)
        return 1;

    bool f = true;

    for (int i = 0; i < num; i++)
    {
        if ((i == K - 1) || (i == num - K))
        {
            if (!((before[K - 1] == after[num - K]) && (before[num - K] == after[K - 1])))
                f = 0;
        }
        else
        {
            if (before[i] != after[i])
                f = 0;
        }
    }

    return f;
}

int main()
{
    int T;
    cin >> T;
    while (T--)
    {
        int num, K, firstdata;
        cin >> num >> K;
        int temp;
        cin >> firstdata;
        Node *head = new Node(firstdata);
        Node *tail = head;
        for (int i = 0; i < num - 1; i++)
        {
            cin >> temp;
            tail->next = new Node(temp);
            tail = tail->next;
        }

        Node *before[num];
        addressstore(before, head);

        head = swapkthnode(head, num, K);

        Node *after[num];
        addressstore(after, head);

        if (check(before, after, num, K))
            cout << 1 << endl;
        else
            cout << 0 << endl;
    }
}

// } Driver Code Ends

// User function Template for C++

/* Linked List Node structure
   struct Node  {
     int data;
     Node *next;
     Node(int x) {
        data = x;
        next = NULL;
  }
  }
*/

// Function to swap Kth node from beginning and end in a linked list.
Node *swapkthnode(Node *head, int n, int k)
{
    if (head == NULL or head->next == NULL or n < k)
        return head;
    if (k > n / 2)
        k = n - k + 1;
    int c = 1;
    Node *curr1 = head, *curr2 = head;

    while (curr1 != NULL and c + 1 < k)
    {
        curr1 = curr1->next;
        ++c;
    }
    c = 1;
    while (curr2 != NULL and c < n - k)
    {
        curr2 = curr2->next;
        ++c;
    }

    if (k == 1)
    {
        head = curr2->next;
        curr2->next->next = curr1->next;
        curr2->next = curr1;
        curr1->next = NULL;
        return head;
    }

    if (k == n / 2 and n % 2 == 0)
    {
        Node *temp = curr2->next;
        curr1->next = temp;
        curr2->next = temp->next;
        temp->next = curr2;
        return head;
    }

    Node *main1next = curr1->next->next;
    Node *main2next = curr2->next->next;

    Node *main1 = curr1->next;
    Node *main2 = curr2->next;

    curr1->next = main2;
    curr2->next = main1;
    main1->next = main2next;
    main2->next = main1next;

    return head;
}
