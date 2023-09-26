class Solution
{
public:
    int search(vector<int> &nums, int target)
    {
        int leftPointer = 0;                // Initialize left pointer at the beginning
        int rightPointer = nums.size() - 1; // Initialize right pointer at the end

        while (leftPointer <= rightPointer)
        {                                                               // While the left pointer is smaller or equal to right
            int midPoint = leftPointer(rightPointer - leftPointer) / 2; // Calculate the midpoint between them
            // If the element in thie midpoint is smaller than target,
            // that means all elements before midpoint are smaller than target
            if (nums[midPoint] < target)
            {
                leftPointer = midPoint + 1; // So move the left pointer to one index after the midpoint
            }
            else if (nums[midPoint] > target)
            {                                // Similarly, if midpoint element is larget than the target
                rightPointer = midPoint - 1; // Move the right pointer to one index before the midpoint
            }
            else
            {
                return midPoint; // Otherwise return the midpoint
            }
        }
        return -1; // If the element is not found, then return -1
    }
};