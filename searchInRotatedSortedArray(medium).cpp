class Solution
{
public:
    int search(vector<int> &nums, int target)
    {
        int size = nums.size(); // Calculate size of nums array
        int left = 0;           // Set left pointer to first index
        int right = size - 1;   // Set right index to last index

        while (left <= right) // Loop until left pointer reaches right
        {
            int midPoint = left + (right - left) / 2; // Calculate midpoint each loop
            // If the left index number is less than midPoint number, it means the left part of the
            // array is sorted.
            if (nums[left] <= nums[midPoint])
            {
                // However, we need to check the sorted part as well for target value
                // So, if the target is between the left index and midPoint index
                if (nums[left] <= target && nums[midPoint] >= target)
                {
                    // We need to move the right pointer
                    right = midPoint - 1;
                }
                else
                {
                    // Otherwie we move the left pointer
                    left = midPoint + 1;
                }
            }
            // Then we do the same thing for the other part of the array
            else
            {
                if (nums[midPoint] <= target && nums[right] >= target)
                {
                    left = midPoint + 1;
                }
                else
                {
                    right = midPoint - 1;
                }
            }
            // Finally, if we find a number ar midPoint index which is equal to target
            if (nums[midPoint] == target)
            {
                return midPoint; // We return it
            }
        }
        return -1; // Otherwise we jus return -1 as question states
    }
};