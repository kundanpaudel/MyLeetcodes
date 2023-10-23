class Solution
{
    // In this solution we use sliding window.
    // We iterate until the end calculating sum. And whenever the sum gets larger than target
    // we loop decreasing the left pointer element from sum until it is less than the target.
public:
    int minSubArrayLen(int target, vector<int> &nums)
    {
        // Initializing the required pointers and sum variable.
        // Minimum set to INT_MAX so that we can use min() function on it later.
        int left = 0, right = 0, sum = 0, minimum = INT_MAX;
        while (right < nums.size())
        {                       // We loop while the right pointer has not reached the end of the list.
            sum += nums[right]; // Calculating the sum each loop.
            while (sum >= target)
            {                                             // If the sum is less than or equal to the given target.
                minimum = min(minimum, right - left + 1); // Then we store the minimum subarray length in minimum variable.
                sum -= nums[left];                        // Then we decrease the left pointer element from the sum.
                left++;                                   // And increase the left pointer to decrease window size.
            }
            right++; // While the sum < target, we increment right pointer and calculate sum each loop.
        }
        if (minimum == INT_MAX)
        {             // If the minimum variable still has value INT_MAX we return zero.
            return 0; // It means there are no such sub arrays.
        }
        return minimum; // Otherwise we return minimum subarray length.

        /*
        // Last if statment can be also written in following form:

        return (minimum == INT_MAX) ? 0 : minimum;
        */
    }
};