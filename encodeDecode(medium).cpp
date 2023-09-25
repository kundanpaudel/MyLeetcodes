class Solution
{
public:
    /*
        The idea behind this solution is to encode provided string in this fashion:
            [string size]+[delimiter '#]+[string]
        Then, we decode it by only pushing string of the size that comes before delimiter '#'
     */
    string encode(vector<string> &strs)
    {
        string result = ""; // Where we store the encoded string.
        for (int i = 0; i < strs.size(); i++)
        {                                                      // Loop through the strs vector
            string str = strs[i];                              // Store each string inside the vector in str variable.
            result += to_string(strs[i].length()) + "#" + str; // Concatenate the string along with it's length and delimiter '#' right before it.
        }
        return result; // Return the encoded string.
    }

    /*
        The idea here is to find length of each string fron our encoded string str.
        Then each time we only take string from the index after the delimiter '#' up to the length.
        We continue doing it until we reach end of the input string.
     */
    vector<string> decode(string &str)
    {
        vector<string> result; // This is the vector of decoded string we return.
        int i = 0;             // Counter for while loop.
        while (i < str.length())
        {              // Loop until end of the string is reached.
            int j = i; // Store value of i in j to calculate the string length later.
            while (str[j] != '#')
            {        // Keep looping until '#' is encountered.
                j++; // Increment the counter j.
            }
            int length = stoi(str.substr(i, j - i)); // Store the length in a variable. Here, length of string is whatever comes before '#'.
            string s = str.substr(j + 1, length);    // Then store the decoded string (whatever comes after # until calulated length) in a variable.
            result.push_back(s);                     // Push the decoded string.
            i = j + 1 + length;                      // Our new string that needs to be decoded starts from the end of the string we just decoded.
        }
        return result; // Return the results.
    }
};
