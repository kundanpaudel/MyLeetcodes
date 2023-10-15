/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution
{
    // The idea here is to use two pointers: slow and fast.
    // Fast moves twice as many nodes as slow.
    // If there is a cycle in the list, they will both eventually meet.
public:
    bool hasCycle(ListNode *head)
    {
        // Edge case: if list is empty
        if (head == nullptr)
        {
            return nullptr;
        }
        // Creating slow and fast pointers
        ListNode *slow = head;
        ListNode *fast = head;

        // Iterating while fast does not point to null or the node pointed by fast does
        // not point to null.
        while (fast->next != nullptr && fast->next->next != nullptr)
        {
            slow = slow->next;       // Slow moves one step.
            fast = fast->next->next; // Fast moves two step.

            // If at any point they meet at same node
            if (slow == fast)
            {
                return true; // That means there is a cycle.
            }
        }
        return false; // Otherwise there is no cycle.
    }
};