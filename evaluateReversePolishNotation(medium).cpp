class Solution
{
public:
    int evalRPN(vector<string> &tokens)
    {
        // Idea is to push the numbers into stack and whenever something other than a number is encountered,
        // we pop two numbers from the stack and perform the operation.
        stack<int> st;

        for (auto num : tokens) // For each string in the given vector
        {
            if (num.size() > 1 || isdigit(num[0])) // We check if the string is single digit or multi-digit number
            {
                st.push(stoi(num)); // If it is we push it into stack
                continue;           // And continue doing it until we find something that is not a digit
            }
            // Then we pop and store the two numbers in two variables
            int firstNum = st.top();
            st.pop();
            int secondNum = st.top();
            st.pop();

            // For each operand that we encounter we perform the operation
            // Note the secondNum being divided by firstNum and not the other way around
            // Same with subtract notation
            if (num == "+")
            {
                st.push(firstNum + secondNum);
            }
            else if (num == "-")
            {
                st.push(secondNum - firstNum);
            }
            else if (num == "*")
            {
                st.push(secondNum * firstNum);
            }
            else
            {
                st.push(secondNum / firstNum);
            }
        }
        return st.top(); // At the end we will have the final result on the top of stack.
    }
};