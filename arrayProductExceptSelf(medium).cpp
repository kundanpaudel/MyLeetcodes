class Solution
{
public:
    /*
        The idea here is to use the same array/vector to save our computations. The computations include
        calculating prefix and postfix array. Here is an example:

        For an array arr = [1, 2, 3, 4] we create prefix array such that at index 0 we save the multiplication
        of all the elements before arr[0] and we continue doing that until the index 3 (for element 4).
        Now, we will end up with array that looks like prefix = [1, 1, 2, 6]. Note the two ones, that's because
        there is no other element before 1 in our array arr so we are saving it manually.

        Same method is used for postfix array but in backward order. However, to keep the time complexity O(n)
        and space complexity of O(1) [results array not counted towards space complexity] we will be doing everything on our results array.
    */
    vector<int> productExceptSelf(vector<int> &nums)
    {
        // This is the vector we will return with same size as nums and filled it with 1's.
        vector<int> result(nums.size(), 1);
        int prefix = 1; // Since there are no elements before the first element we will use this default value.
        for (int i = 0; i < nums.size(); i++)
        {                              // Iterating through the nums array.
            result[i] = prefix;        // We are saving the prefix values into our output array.
            prefix = prefix * nums[i]; // We need to change our prefix because we are multiplying every element before the current one.
        }

        int postfix = 1; // Since there are no elements after the last one.
        for (int i = nums.size() - 1; i >= 0; i--)
        {   // Iterating the nums array/vector from the end. nums.size()-1 done because c++ indexing starts from zero.
            // We already have prefix values at result vector so we just need to multiply with whatever comes after the current element.
            // This means, for array [1, 2, 3, 4] if we consider element 3, we already have 1*2 in our prefix array, now all we need to do is
            // multiply 1*2 with 4, which comes after 3.
            result[i] = postfix * result[i];
            // We need to change our postfix value here. This value will come from nums array and not result array because the result array already has
            // prefix multiplications saved in it.
            postfix = postfix * nums[i];
        }
        return result; // We return the final results here.
    }
};