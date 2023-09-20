class Solution
{
public:
    int characterReplacement(string s, int k)
    {
        vector<int> count(26); // To store the count of characters
        int i = 0;
        int j = 0;
        int result = 0;   // Length of longest substring
        int maxCount = 0; // Size of current window

        while (j < s.size())
        {
            // To store in vector indices.
            // if s[j] = 'A' then s[j]-'A' gives 0. So we increment the value at index 0.
            count[s[j] - 'A']++;
            // We store the most frequent character in the given string here.
            maxCount = max(maxCount, count[s[j] - 'A']);
            // Check if the size of current window minus the maxCount is greater than k.
            // This means we are checking how many replacements we are allowed to do in current window.
            if (j - i + 1 - maxCount > k)
            {
                count[s[i] - 'A']--; // Decrease the character count and
                i++;                 // move the pointer.
            }
            // Store the largest valid window/substring length in result variable.
            result = max(result, j - i + 1);
            // Increment the right pointer
            j++;
        }
        return result; // Return the longest substring length
    }
};