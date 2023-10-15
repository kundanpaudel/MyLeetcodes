class Solution
{
    // The idea for this solution is to treat the question as a linked list and not array.
    // We use slow and fast pointers to make two passes.
    // In first pass, we find the element/node where both slow and fast pointers meet.
    // In second pass we create new slow pointer from first index and move it as well as
    // the previous slow pointer by one step at a time until they meet.
    // The position where they meet holds the duplicate element.
public:
    int findDuplicate(vector<int> &nums)
    {
        // Initiate slow and fast pointers
        // We are treating the array as a linked list
        int slow = nums[0];
        int fast = nums[nums[0]];

        while (slow != fast)
        {                            // First pass to find the intersection point of both pointers.
            slow = nums[slow];       // move one step
            fast = nums[nums[fast]]; // move two step
        }

        slow = 0; // Reinitiate the slow pointer at starting index
        while (slow != fast)
        { // Second pass to find the duplicate element
            slow = nums[slow];
            fast = nums[fast];
        }

        return slow;
    }
};