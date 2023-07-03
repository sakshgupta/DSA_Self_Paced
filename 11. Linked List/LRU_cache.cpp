#include <bits/stdc++.h>
using namespace std;

// design the class in the most optimal way

class LRUCache
{
public:
    // Constructor for initializing the cache capacity with the given value.
    class Node
    {
    public:
        int key;                   // holds the given key
        int val;                   // holds the given value
        Node *next;                // pointer to the next node in the data structure
        Node *prev;                // pointer to the previous node in the data structure
        Node(int _key, int _value) // constructor for the Node class
        {
            key = _key;   // set the key
            val = _value; // set the value
        }
    };

    Node *head = new Node(-1, -1);
    Node *tail = new Node(-1, -1);
    int capi;
    unordered_map<int, Node *> m;

    //  Constructor takes in a capacity for caching
    LRUCache(int cap)
    {
        // store the capacity in a private variable
        capi = cap;

        // set next pointer of head node to be tail
        head->next = tail;

        // set prev pointer of tail node to be head
        tail->prev = head;
    }

    void addnode(Node *newnode)
    {
        Node *temp = head->next;
        newnode->next = temp; // Point newnode's next pointer to the current second node.
        newnode->prev = head; // Point newnode's previous pointer to the head.
        head->next = newnode; // Set the next pointer of the head node to newnode.
        temp->prev = newnode; // Set the previous pointer of the current second node to newnode.
    }

    /*
    This function deletes a given node from a doubly-linked list. It takes in the node to be deleted as an argument, and proceeds to remove the node by updating references of surrounding nodes accordingly.
    */
    void deletenode(Node *delnode)
    {
        // Get the previous and next nodes around the node to be deleted
        Node *delprev = delnode->prev;
        Node *delnext = delnode->next;
        // Update the surrounding nodes to reference each other instead of the node being deleted
        delprev->next = delnext;
        delnext->prev = delprev;
    }

    // Function to return value corresponding to the key.
    int GET(int key)
    {
        // Check if the key exists in the map
        if (m.find(key) != m.end())
        {
            // Retrieve the Node associated with the key
            Node *resnode = m[key];

            // Retrieve and store the value associated with the Node
            int res = resnode->val;

            // Erase the original key-value pair from the map
            m.erase(key);

            // Delete the node from its original position
            deletenode(resnode);

            // Add the node to the beginning of the map
            addnode(resnode);

            // Update the map with the new key-value pair
            m[key] = head->next;

            // Return the stored result value
            return res;
        }

        // Else, return -1
        return -1;
    }

    // Function for storing key-value pair.
    void SET(int key, int value)
    {
        // Checks if key is already in map
        if (m.find(key) != m.end())
        {
            // If so, store node in exisnode, erase key from map and delete node
            Node *exisnode = m[key];
            m.erase(key);
            deletenode(exisnode);
        }
        // Checks capacity of map
        if (m.size() == capi)
        {
            // If over capacity, erase tail previous's key from map and deleted node
            m.erase(tail->prev->key);
            deletenode(tail->prev);
        }

        // Adds new node to doubly linked list
        addnode(new Node(key, value));

        // Sets map with new node's key
        m[key] = head->next;
    }
};

/**
main function to interact with the LRU cache.
Reads an "capacity" to set up the Cache.
Reads a query which can be either, "s" or "g", where "s" stands for Set and "g" stands for Get.
If it is "s," it reads two integers indicating the key and the value of the element you want to set in the Cache.
Else, if it is "g," it only reads one integer which stands for the key to search its value in the Cache.
All values found are print on the console.
*/
int main()
{
    int capacity;
    cin >> capacity;
    LRUCache *cache = new LRUCache(capacity);

    int queries;
    cin >> queries;
    while (queries--)
    {
        string q;
        cin >> q;
        if (q == "s")
        {
            int key;
            cin >> key;
            int value;
            cin >> value;
            cache->SET(key, value);
        }
        else
        {
            int key;
            cin >> key;
            cout << cache->GET(key) << " ";
        }
    }
    cout << endl;
}
