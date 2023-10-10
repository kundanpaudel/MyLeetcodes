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
    // The idea here is to create a new list to store the elements from both list1 and list2 in sorted order.
    // For that we need a head pointer for new list an another pointer to traverse it while adding elements.
public:
    ListNode *mergeTwoLists(ListNode *list1, ListNode *list2)
    {
        if (list1 == NULL && list2 == NULL)
        {                // If both lists are empty
            return NULL; // Return null
        }
        if (list1 == NULL)
        { // If list1 is empty we only have list2.
            return list2;
        }
        if (list2 == NULL)
        { // If list2 is empty we  only have list1.
            return list1;
        }

        ListNode *temp = new ListNode; // Storing head of new list here.
        ListNode *curr = temp;         // Moving through the new list and adding elements using this.

        while (list1 != NULL && list2 != NULL)
        { // While both of the lists have not reached the end.
            if (list1->val <= list2->val)
            {                        // If the list1 value is smaller
                curr->next = list1;  // Then it is added to the new list.
                list1 = list1->next; // Then we move forward in list1.
            }
            else
            {                       // Otherwise it means list2element is smaller
                curr->next = list2; // So we add that one insted.
                list2 = list2->next;
            }
            // After that we need to move the curr pointer to the element that was just added.
            curr = curr->next;
        }

        // Handling edge cases here
        // If either one of the list is shorter, we add the longer one to the new list.
        if (list1 == NULL)
        {
            curr->next = list2;
        }
        else
        {
            curr->next = list1;
        }

        // Then we return the head we have stored.
        // Since the elements were added to the list only from temp->next we return it
        // insted of just temp.
        // Returning temp will give us an extra element '0' at the beginning.
        return temp->next;
    }
};
