class Solution
{
public:
    int maxProfit(vector<int> &prices)
    {
        int rightPointer = 0; // We initilaize left and right pointer from index 0.
        int leftPointer = 0;
        int maxProfit = 0; // Set the max profit to zero as well.

        while (rightPointer < prices.size())
        { // Loop until right pointer reaches end of the array.
            if (prices[leftPointer] <= prices[rightPointer])
            {                               // If price at left is smaller than price at right
                leftPointer = rightPointer; // Change left pointer location, increment right pointer outside the if statement
            }
            else
            {
                maxProfit = max(maxProfit, prices[rightPointer] - prices[leftPointer]); // Otherwise calculate the max profit for current indices,
                // then increase right pointer only outside if statement.
            }
            j++; // Increment right pointer for each case.
        }
        return maxProfit; // Return max profit here.
    }