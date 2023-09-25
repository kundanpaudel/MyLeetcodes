class Solution
{
public:
    /*
        The idea here is to create three different matrices for rows, columns, and 3x3 squares.
        Each of those matrices will be boolean type which will turn cell to true if that number is found while looping through the board.
        For example at board[2][5] there is a number 5 then, rows[2][5], cols[5][5] and square[1][5] will all be set to true.
        There are 9 3x3 squares which we will give indices 0 to 8.
    */
    bool isValidSudoku(vector<vector<char>> &board)
    {
        const int size = 9;                 // Size of sudoku board is always 9x9.
        bool rows[size][size] = {false};    // Rows matrix
        bool cols[size][size] = {false};    // Columns matrix
        bool squares[size][size] = {false}; // 3x3 squares matrix

        for (int r = 0; r < size; r++)
        { // Iterating through rows
            for (int c = 0; c < size; c++)
            { // Iterating through columns
                if (board[r][c] == '.')
                { // If we see '.' in our input, we simply skip it
                    continue;
                }
                // Our input is in char, but we need it to be int so we are converting it here.
                // Also, note that -1, that is done because we get numbers 1 to 9 when we convert the chars from input.
                // However, our indices in c++ need to be from 0 to 8.
                int currentNumber = board[r][c] - '0' - 1;
                int area = (r / 3) * 3 + (c / 3); // There are 9 3x3 squares. This is to denote each of those squares by numbers 0 to 8.
                // If in any row, column, or squares we find that the boolean for currentNumber is true then that means there is already
                // a number with that same value. That is, it is a repeating element. So we just return false.
                if (rows[r][currentNumber] || cols[c][currentNumber] || squares[area][currentNumber])
                {
                    return false;
                }
                // Otherwise we change the boolean value of eachmatrix to be true to denote that we have seen that number and it is not
                // a repetition.
                rows[r][currentNumber] = true;
                cols[c][currentNumber] = true;
                squares[area][currentNumber] = true;
            }
        }
        return true; // If all input passes through the loops, then we just return true.
    }
};