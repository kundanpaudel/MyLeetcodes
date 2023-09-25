int lengthOfLongestSubstring(string s)
{
    unordered_set<char> chars; // This set stores unique characters in the current substring.
    int i = 0, j = 0;          // Two pointers (i and j) define the current substring.
    int maxSize = 0;           // Stores the maximum length of the substring without repeating characters.

    while (j < s.length())
    {
        // While there are repeating characters in the current substring.
        while (chars.find(s[j]) != chars.end())
        {
            chars.erase(s[i]); // Remove the character at position i from the set.
            i++;               // Move the left pointer (i) to the right to shrink the substring.
        }

        // Update the maximum length if the current substring is longer.
        maxSize = max(maxSize, j - i + 1);

        // Add the character at position j to the set.
        chars.insert(s[j]);

        // Move the right pointer (j) to the right to expand the substring.
        j++;
    }

    return maxSize; // Return the maximum length of a substring without repeating characters.
}
