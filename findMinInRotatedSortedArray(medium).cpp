class Solution
{
public:
    // The idea here is to check if left pointer element is less than the mid element of the list.
    // If true, it means the left side is sorted and we only need to search the right part.
    // If false, we do the opposite.
    int findMin(vector<int> &nums)
    {
        int minimum = nums[0];       // The initial minimum is set to first element.
        int left = 0;                // The left index starts from zero.
        int right = nums.size() - 1; // The right index starts from the very end.

        while (left <= right)
        {                                             // We loop until the end of the loop
            int midPoint = left + (right - left) / 2; // And calculate the midpoint as we do so.
            if (nums[left] < nums[right])
            { // If the left pointer element is less than the right pointer element
                // That means the window is sorted
                // So in that case we take the minimum of the current minimum and left pointer element
                minimum = min(minimum, nums[left]);
                break; // And break the loop because we are returning minimum at end anyway.
            }
            if (minimum <= nums[midPoint])
            { // If the minimum value so far is less than or equal to he mid point element
                // That means the left side is sorted, so we move the window
                left = midPoint + 1;
            }
            else
            {
                // Otherwise we keep track of the minimum and move the window
                minimum = min(minimum, nums[midPoint]);
                // The right side is sorted
                right = midPoint - 1;
            }
        }
        return minimum; // Return the minimum value here.
    }
};
