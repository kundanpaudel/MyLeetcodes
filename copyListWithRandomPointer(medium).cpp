/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;

    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution
{
public:
    Node *copyRandomList(Node *head)
    {
        // Creating map to store nodes according to their addresses.
        unordered_map<Node *, Node *> nodes;
        Node *h = head; // Storing head address in h for traversal.

        while (h)
        {                                // Loop while h is not null
            nodes[h] = new Node(h->val); // At address h in the map, store the value h node has in it.
            h = h->next;                 // Keep moving the h pointer.
        }

        h = head; // Re-initialize the h pointer for second pass into a loop.
        while (h)
        {                             // While h is not null
            Node *newNode = nodes[h]; // Create a new node and copy the value in the map.
            // The next node points to whatever the current node in map is pointing to.
            newNode->next = nodes[h->next];
            // Similarly the random pointer points at whatever the map node is pointing to.
            newNode->random = nodes[h->random];
            h = h->next; // Keep moving the h pointer.
        }
        // Return the head of the linked list which is stored in the map.
        return nodes[head];
    }
};