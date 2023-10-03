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
    ListNode *reverseList(ListNode *head)
    {
        // Checking the edge case
        // If the head itself is null that means there is no linked list
        // If head is not pointing to any other element, only head exists in the list.
        if (head == nullptr || head->next == nullptr)
        {
            return head; // In either case we return head.
        }
        // Create a pointer that points before current element
        ListNode *prev = nullptr;
        // Create a pointer that points at the current element
        ListNode *current = head;

        // We loop until current element is equal to null
        // so that prev pointer will point to the last element (new head)
        while (current != nullptr)
        {
            // Creating a temporary pointer for next element on the list
            ListNode *temp = current->next;
            // Current pointer needs to point to previous element to reverse the list.
            current->next = prev;
            // Then current has to be moved to the next element of the list to repeat
            // same process again.
            current = temp;
        }
        // At the end the new head of the list will be pointed by prev pointer.
        return prev;
    }
};