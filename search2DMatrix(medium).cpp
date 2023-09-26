class Solution
{
public:
    bool searchMatrix(vector<vector<int>> &matrix, int target)
    {
        int rows = matrix.size();    // Store number of rows
        int cols = matrix[0].size(); // Store number of columns assuming all rows have same number of columns

        int left = 0;                // Initialize left pointer
        int right = rows * cols - 1; // Initialize right pointer by flattening our matrix

        while (left <= right)
        {                                             // While the left pointer is less than right
            int midPoint = left + (right - left) / 2; // Calculate the midPoint
            // Since the matrix has been flattened, the midpoint/cols will give us the row number
            // It essentially means how many rows we have passed
            // Similarly, midpoint%cols give us the position of the midvalue within the row
            // So, remainder = column number, and quotient=row number
            int midValue = matrix[midPoint / cols][midPoint % cols];
            // Then we just perform binary search
            if (target == midValue)
            {
                return true;
            }
            else if (target > midValue)
            {
                left = midPoint + 1;
            }
            else
            {
                right = midPoint - 1;
            }
        }
        return false; // If binary search does not find it, we simply return false.
    }
};