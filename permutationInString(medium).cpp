class Solution
{
public:
    bool checkInclusion(string s1, string s2)
    {
        int len1 = s1.length();
        int len2 = s2.length();

        if (len1 > len2)
        { // If the permutation string is longer, return false
            return false;
        }

        vector<int> s1Count(26); // Vectors to store the count of each alphabet in s1 and s2
        vector<int> s2Count(26);

        for (int i = 0; i < len1; i++)
        {                           // Looping until the end of s1
            s1Count[s1[i] - 'a']++; // Incrementing the count of each alphabet found in both strings essentially creating a window
            s2Count[s2[i] - 'a']++;
        }

        if (s1Count == s2Count)
        { // If the first window that is created has the permutation string s1, return true
            return true;
        }

        for (int i = len1; i < len2; i++)
        {                                  // Otherwise we loop, moving the window
            s2Count[s2[i - len1] - 'a']--; // In the new window we remove the first element from previous window
            s2Count[s2[i] - 'a']++;        // Then we add a new element after the previous window
            if (s1Count == s2Count)
            { // If the current window consists same number of alphabet count as pwemutation string we return true
                return true;
            }
        }
        return false; // If looped through string but no permutation found, return false.
    }
};
