class Solution
{
public:
    vector<vector<string>> groupAnagrams(vector<string> &strs)
    {
        vector<vector<string>> groupedAnagrams;     // Create a vector to store anagram groups.
        unordered_map<string, vector<string>> keys; // Map to store the sorted strings (keys).

        string temp; // Temporary variable to store words from the input vector.

        // Iterate through each word in the input vector strs.
        for (auto word : strs)
        {
            temp = word;                    // Copy the word to the temp variable.
            sort(temp.begin(), temp.end()); // Sort the characters in the word alphabetically.
            keys[temp].emplace_back(word);  // Store the sorted word as a key and associate the original word with it.
        }
        // Iterate through the keys map.
        for (auto it = keys.begin(); it != keys.end(); ++it)
        {
            groupedAnagrams.emplace_back(it->second); // Add the anagram group (a vector of original words) to the result.
        }

        return groupedAnagrams; // Return the grouped anagrams.
    }
};
