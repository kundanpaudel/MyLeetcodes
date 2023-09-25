class Solution
{
    // This problem is solved using recursion for simplicity.
public:
    vector<string> generateParenthesis(int n)
    {                                  // Main function for the Solution class
        vector<string> result;         // Vector to store the strings
        generate(n, 0, 0, "", result); // Calling the helper function to create valid parentheses strings
        return result;                 // Returning the collection of generated valid parentheses
    }

private:
    void generate(int n, int open, int close, string str, vector<string> &result)
    { // Helper Function
        if (open == n && close == n)
        {                          // If the number of open and closed parentheses are equal to the provided number n
            result.push_back(str); // Then it means we have generated valid string, so we push it.
            return;                // We then us return to exit current recursive call
        }
        if (open < n)
        {                                                  // If the number of open parentheses is less than the goal
            generate(n, open++, close, str + '(', result); // Make recursive call increasing the open parentheses number and append a opening parentheses
        }
        if (close < open)
        {                                                  // Similarly, if close parentheses is less than the open ones
            generate(n, open, close++, str + ')', result); // make recursive call to increase the closed parentheses number and append it as well to str
        }
    }
};