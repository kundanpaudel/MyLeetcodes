class Solution
{
    // Logic: use three pointers and keep track of minimum difference and sum.
    // Similar to 3Sum
public:
    int threeSumClosest(vector<int> &nums, int target)
    {
        int size = nums.size();                            // Storing size of given array.
        sort(nums.begin(), nums.end());                    // Sorting the array so that it is optimal for using pointers.
        int left = 0, minDifference = INT_MAX, minSum = 0; // Initializing left pointer and other variables.

        while (left < size - 2) // Left pointer goes till size - 2 because we need 2 more element to calculate sum of 3 elements
        {
            int middle = left + 1, right = size - 1; // Initializing the left and middle pointer.
            while (middle < right)                   // When the middle pointer is smaller than right
            {
                int sum = nums[left] + nums[middle] + nums[right]; // We calculate sum of all three elements.
                int difference = target - sum;                     // Then we calculate difference from target as well.
                // Checking if absolute value of difference is smaller than the minimum difference we have saved so far.
                if (abs(difference) < minDifference)
                {
                    minDifference = abs(difference); // If so then minimum difference will be updated.
                    minSum = sum;                    // And so will be the minimum sum.
                }
                if (sum > target) // If the sum is greater than target it means right value is large.
                {
                    right--; // So we decrease index
                }
                else if (sum < target) // And in contracy situation, middle value is smaller
                {
                    middle++; // So we increase index.
                }
                else // In case the sum and target are equal the difference is zero.
                {
                    return sum; // Difference cannot be less than zero so we just retun the sum.
                }
            }
            left++; // We increase the left pointer for first loop.
        }
        return minSum; // At the end we return the minimum sum.
    }
};