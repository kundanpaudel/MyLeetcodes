class Solution
{
public:
    vector<vector<int>> threeSum(vector<int> &nums)
    {
        vector<vector<int>> result; // This is the vector we return at the end.
        int size = nums.size();     // Storing the size of the vector.
        if (size < 3)
        {                  // We need to have at least 3 elements to calculate the sum.
            return result; // If not we return empty vector.
        }
        sort(nums.begin(), nums.end()); // Sorting the vector so we can use 2 pointers effectively.
        // Loop from 0 to size-2 index because we need at least 3 elements for sum.
        // For example, if we reach size-1 then we only have one element left along with current ith element to calculate sum.
        for (int i = 0; i < size - 2; i++)
        {
            if (nums[i] > 0)
            { // If our ith term is greater than zero that means there are no negative numbers after it. So we break the loop.
                break;
            }
            if (i > 0 && nums[i - 1] == nums[i])
            { // If we find same value elements, we just continue until we find a different one.
                continue;
            }
            int j = i + 1;    // First pointer starts from i+1 since we already have nums[i]
            int k = size - 1; // Second pointer starts from size-1 (Check twoSumII(medium).cpp for this method)
            while (j < k)
            {                                          // We loop until j and k cross paths
                int sum = nums[i] + nums[j] + nums[k]; // We calculate the sum for each combination of j and k with i
                // Folowing is the same logic from twoSumII
                if (sum > 0)
                { // If sum is greater than zero we move the second pointer backwards.
                    k--;
                }
                else if (sum < 0)
                { // If sum is less than zero, we move first pointer forwards.
                    j++;
                }
                else
                {                                                   // If sum is equal to zero
                    results.push_back({nums[i], nums[j], nums[k]}); // We push the numbers into our results vector.
                    // The following two loops are done so that if we encounter duplicates, we just skip them.
                    while (j < k && nums[j] == nums[j + 1])
                    {
                        j++;
                    }
                    j++; // If there are no duplicates we move first pointer by one step.
                    while (j < k && nums[k] == nums[k - 1])
                    {
                        k--;
                    }
                    k--; // Similarly, we move second pointer by one step.
                }
            }
            return result; // Returning the result vector here.
        }
    }
};