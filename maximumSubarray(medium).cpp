class Solution
{
    // The idea here is to use sliding window technique while keeping track of the sum each loop.
    // If we find that the sum is less than zero then we simply set sum as zero and move left pointer to right +1.
    // And we also move right pointer one step.
    // What I don't like: Seems like the we need to assume sum will always be positive here.
    // However, it is not mentioned in the question.
public:
    int maxSubArray(vector<int> &nums)
    {
        // Initializing all the required variables.
        int sum = 0, largest = 0, left = 0, right = 0;
        while (right < nums.size())
        {                                // We loop until we dont reach end for nums list.
            sum += nums[right];          // The current sum will be calculated each loop.
            largest = max(largest, sum); // Save the largest sum so far each loop.
            if (sum < 0)
            {                     // If the current sum is less than zero
                left = right + 1; // Then we move left pointer to right+1 so that when we do right++ later we end up in same index.
                sum = 0;          // Then we set sum to zero.
            }
            right++; // Incrementing the right pointer.
        }
        return largest;
    }
};
