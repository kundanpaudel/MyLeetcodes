/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution
{
    // The idea here is to split the list into 2 parts using slow and fast pointer
    // Slow pointer moves one node at a time.
    // Fast pointer moves two nodes at a time.
    // Then we reverse the second part of the list and merge it with first part.
    // Create helper functions reverse and merge.
private:
    // Helper function to reverse the second part of the list.
    ListNode *reverse(ListNode *head)
    {
        ListNode *prev = nullptr; // Track previous node.
        ListNode *curr = head;    // Track current node.

        while (curr != nullptr) // While we dont reach the end of the list.
        {
            ListNode *temp = curr->next; // Create a temporary pointer to next node.
            curr->next = prev;           // The current node points to previous node.
            prev = curr;                 // The previous pointer is now pointing to current node.
            curr = temp;                 // And the current node advances to temp (next) node.
        }
        return prev; // New head will be at the prev node when list is reversed.
    }

    // Helper function to merge the two lists
    void merge(ListNode *list1, ListNode *list2)
    {
        while (list1 != nullptr) // While first list end is not reached.
        {
            ListNode *pointer1 = list1->next; // Create pointer for next node of first list.
            ListNode *pointer2 = list2->next; // Create pointer for next node of second list.
            list1->next = list2;              // The first list node points to second list node.
            if (pointer1 == nullptr)          // If the next node of first list is null.
            // It means the first list only has 1 node.
            {
                break;              // In that case we break from the loop.
            }                       // Otherwise:
            list2->next = pointer1; // The second list node needs to point to next node of first list.
            list1 = pointer1;       // Then first list pointer advances to next node.
            list2 = pointer2;       // Second list pointer advances to next node.
        }
    }

public:
    void reorderList(ListNode *head)
    {
        ListNode *prev = nullptr; // Tracking the node before slow pointer.
        // Both slow and fast pointer start from the head.
        ListNode *slow = head;
        ListNode *fast = head;

        // While the fast pointer has not reached the end of the list
        // This condition depends on the list node number:
        // if list is even fast==nullptr else fast->next==nullptr
        while (fast != nullptr && fast->next != nullptr)
        {
            prev = slow;             // Previous pointer equals to slow pointer.
            slow = slow->next;       // While slow pointer moves to next node.
            fast = fast->next->next; // And fast pointer moves two nodes further.
        }
        // By the end of the loop prev pointer will be at the center of the list.
        // This means to create new list we need to split at prev so prev->next=null is done.
        prev->next = nullptr;

        ListNode *l1 = head; // New list1 will start from the head until prev.
        // Second list will start from the slow pointer until the fast.
        // This list is reversed to meet the condition asked by the question.
        ListNode *l2 = reverse(slow);

        merge(l1, l2); // We then merge them
    }
};