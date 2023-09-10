class Solution
{
public:
    int combinationSum4(vector<int> &nums, int target)
    {
        // Vector of size target +1 created in order to include all elements from 0 to the target
        // For example, for target = 4, we need to store 0,1,2,3,4 making size = target + 1
        vector<unsigned int> dp(target + 1, 0); // To store the number of ways of making sum.
        dp[0] = 1;                              // This is done because there is only 1 way to make the sum of zero. That is, not selecting any numbers.

        // Now we iterate from 1 to target because we already have a base case for i = 0 by dp[0] = 1.
        // Here, i is our target sum for each iteration.
        // For instance, for list [1, 2, 3, 4] we first find how many ways there are to make sum of 1 from the given list of numbers.
        // Then we do the same for 2, 3, 4. Note that we already have base case set for dp[0] = 1 so we are starting from 1.
        for (int i = 1; i <= target; i++)
        {
            for (int num : nums)
            {   // Iterating through the given array/vector and saving it in nums integer variable.
                // If our target sum is greater or equal to the element in the list.
                // This conditional is done to only consider the elements that can be used to add up to the current target sum 'i'.
                // Note that the sum 'i' that we are trying to find cannot be less than the num itself that's the idea behind condition i >= num.
                if (i >= num)
                {
                    // Here we are saving the count of combinations to make the sum 'i'.
                    // For instance, in each loop we are saving the count of making sum of 1, 2, 3, 4 in the list [1,2,3,4].
                    // Here, dp[i-num] gives us combinations to make a small number from the given list.
                    // So, here we are basically including the number of ways we can include 'num' in making our target sum 'i'.
                    // For example, if we consider i = 4 and num = 2 then, dp[4] = dp[4-2] => dp[2] which means we are adding
                    // the combinations that make sum 2 using elements from the given list. And we are now adding it to
                    // the combinations that make 4 using elements from the given list.
                    // So, for list [1, 2, 3, 4] when we have dp[4] we are adding all combinations to make 0, 1, 2, and 3.
                    dp[i] += dp[i - num];
                }
            }
        }
        // Here we are just returning the number of combinations for the target variable that is stored in our vector.
        return dp[target];
    }
};