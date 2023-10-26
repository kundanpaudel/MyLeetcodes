class Solution
{
public:
    string minWindow(string s, string t)
    {
        unordered_map<char, int> tMap; // Map to store the characters in string t and their frequencies
        // Loop to calculate frequencies of chars in t
        for (auto chars : t)
        {
            tMap[chars]++;
        }

        int i = 0, j = 0;                    // Pointers for the window we need to create for the substrings
        int counter = t.length(); // Number of characters we have in t that we need to have in s as well
        int start = 0;            // Start of substring we will return
        int minLength = INT_MAX;  // The minimum length of the substring

        while (j < s.length())
        { // Moving a pointer until the end of the string creating windows
            if (tMap[s[j]] > 0)
            { // If the current character in s is in tMap, then we decrese the counter
                counter--;
            }
            tMap[s[j]]--; // If not, we decrese the frequency of the current character (which is not in t), making it negative.
            j++;          // Go to next character

            while (counter == 0)
            { // When we have found all characters of t in substring window of s
                if (j - i < minLength)
                {                      // If the length of current substring is less than the minimum length we have so far
                    start = i;         // Then substring start will be set to the first character pointer
                    minLength = j - i; // And the minimum length of the substring will be set to j-i (length of the current window)
                }
                // Otherwise we increase the current character count of s[i] in tMap.
                // Note that for any character that are not in t but are in s, their frequency have been negative since we did tMap[s[j]]--; earlier.
                // So, when we do tMap[s[i]]++; the only characters that will have frequency greater than zero are the characters that are
                // present in t. Others will be either less than zero or equal to zero.
                tMap[s[i]]++;
                // If the i-th character of s has frequency greater than zero in tMap, that means we have character that we need in the substring.
                // Since we are moving the left pointer from the character we need in the substring, we have to increase the counter.
                if (tMap[s[i]] > 0)
                {
                    counter++;
                }
                i++; // Moving the left pointer
            }
        }
        // If the minimum length of the substring/window has changed from what we set earlier
        // We return the substring.
        if (minLength != INT_MAX)
        {
            return s.substr(start, minLength);
        }
        return ""; // Otherwise we return empty string.
    }