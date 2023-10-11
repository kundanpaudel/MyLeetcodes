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
public:
    ListNode *removeNthFromEnd(ListNode *head, int n)
    {
        // Edge case if the list given is empty then return null.
        if (head == nullptr)
        {
            return nullptr;
        }
        // Initialize both slow and fast pointers.
        ListNode *slow = head;
        ListNode *fast = head;

        // We move the fast pointer n nodes away from slow pointer.
        while (n > 0)
        {
            fast = fast->next;
            n--;
        }

        // If the node to be removed is the head node.
        // This means fast pointer will reach the very end of the list.
        if (fast == nullptr)
        {
            return head->next; // return the next node of the list.
        }

        // Otherwise until we reach fast->next=nullptr
        while (fast->next != nullptr)
        {
            // We move both slow and fast pointers.
            // By the end of this loop the slow pointer will be right
            // before the node that needs to be removed.
            slow = slow->next;
            fast = fast->next;
        }
        // Then we remove the target node.
        slow->next = slow->next->next;
        return head; // Return the list with deleted node.
    }
};
