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
    // The idea here is to sum each number in the list and keep track of the carry over.
    // Each node needs to have single digit so modulus needs to be used.
    // We create a new list and do not modify the given lists.
public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
    {
        // Creating new list to store the total sum and return at the end.
        ListNode *newList = new ListNode;
        // Curr initialized to newList: will hold the sum values for each iteration.
        ListNode *curr = newList;
        int carry = 0; // Variable to store the carry over of the sum of digits.

        while (l1 != nullptr || l2 != nullptr)
        { // We loop until we reach end of either of lists
            // Check if end of list is reached, if not, store the value of the node in
            // the corresponding variable val1 or val2.
            // If end of list is reached then store value as zero.
            int val1 = (l1 != nullptr) ? l1->val : 0;
            int val2 = (l2 != nullptr) ? l2->val : 0;
            int sum = val1 + val2 + carry; // Calculate sum
            carry = sum / 10;              // Calculate carry over
            // The current node needs to point to new node with single digit.
            // Using modulus assures that we have single digit in each new node.
            curr->next = new ListNode(sum % 10);
            curr = curr->next; // Move curr pointer for new digit in next loop.

            // If we have not reached the end of the either of the list, we move to next node.
            if (l1 != nullptr)
            {
                l1 = l1->next;
            }
            if (l2 != nullptr)
            {
                l2 = l2->next;
            }
        }

        // Handling the edge case if the last elements sum has a carry over.
        if (carry)
        {                                     // If carry is greater than zero
            curr->next = new ListNode(carry); // Create a new node with carry value and link it.
        }
        return newList->next; // Return the new formed list.
    }
};