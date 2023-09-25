class Solution
{
public:
    int maxArea(vector<int> &height)
    {
        int tempArea = 0;          // Variable to store temporary area
        int maxArea = 0;           // Variable to return at the end
        int i = 0;                 // First pointer initialization
        int j = height.size() - 1; // Second pointer initialization
        while (i < j)
        {                               // While the pointers have not crossed paths
            if (height[i] <= height[j]) // If height at first pointer is equal or less than second pointer
            {
                tempArea = height[i] * (j - i); // Calculate the area from the smaller height and store in tempArea
                i++;                            // Increase our pointer
            }
            else // Otherwise
            {
                tempArea = height[j] * (j - i); // Calculate the area from the second pointer (smaller in this case) and store in tempArea
                j--;                            // Decrease the pointer
            }
            maxArea = max(tempArea, maxArea); // Find which one is greater the current area or the area calculated before
        }
        return maxArea; // Then return the maximum area.
    }
};