class Solution
{
public:
    bool isValid(string s)
    {
        // Create mao of brackets where key are the closing brackets
        // We are using map so that search/find will be linear time
        unordered_map<char, char> brackets = {
            {')', '('},
            {']', '['},
            {'}', '{'}};

        stack<char> st; // Crating a stack with built in c++ function

        for (auto c : s)
        { // For every character in string s
            if (brackets.find(c) != brackets.end())
            { // If we find the brackets we are looking for in the map
                if (st.empty())
                {                 // But if the stack is empty, meaning no opening brackets have been found
                    return false; // then return false
                }
                if (st.top() != brackets[c])
                {                 // If the top of stack is not the same as the brackets pairs in our map
                    return false; // then return false
                }
                st.pop(); // Otherwise pop the top element from the stack
            }
            else
            {               // If we don't find the brackets we are looking for in the map
                st.push(c); // simply push into the stack
            }
        }
        return st.empty(); // Return if the stack is empty or not.
    }
};
