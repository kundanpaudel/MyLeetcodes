class Solution
{
public:
    /*
        The idea for this solution is to have two pointers, one starts from the beginning and one from the end of the string.
        We check for each character of the string whether it is alphanumeric for both pointers.
        Then only once we find an alphanumeric character, we change it to lowercase and compare them.
        If they are not the same character while comparing, we return false.
        If the string passes through all loops, we return true.
    */
    bool isPalindrome(string s)
    {
        int i = 0;              // Starting pointer
        int j = s.length() - 1; // End pointer

        while (i < j)
        { // While the pointers have not crossed paths.
            while (!isalnum(s[i]) && i < j)
            {        // While the current character for pointer i is not alphanumeric and i<j
                i++; // Increase the pointer to next character in the string
            }
            while (!isalnum(s[j]) && i < j)
            {        // While current character for pointer j is not alphanumeric and i<j
                j--; // Decrease the pointer to previous character in the string
            }
            if (tolower(s[i]) != tolower(s[j]))
            {                 // Once we have found alphanumeric characters in both starting and end pointer we compare them.
                return false; // If they are not the same at any point, we return false.
            }
            // If the pointers pass the above conditional statement, we increment one pointer and decrement other.
            i++;
            j--;
        }
        return true; // If the string passes all the loops, we return true.
    }
};