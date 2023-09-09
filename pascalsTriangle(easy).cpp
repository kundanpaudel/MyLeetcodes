class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        if(numRows<=0){ // edge case, if rows is less than or equal to zero, return empty vector
            return {};
        }
        vector<vector<int>> triangle; // we return this vector
        for(int i = 0; i < numRows; i++){ // iterate from top to bottom of our triangle
            vector<int> row(i+1, 1);
            // We need to add previous row elements only for 2nd element
            // until one element before the last element.
            for(int j = 1; j<i; j++){ // Iterate from second element till second last element.
            // From second to second last element:
            // add the j index and j-1 index element of previous(i-1) row
            // then store it in j index of current(i) row.
            // for index 2 we add 1 and 2 from previous
            // for index 3 we add 2 and 3 from previous etc.
                row[j] = triangle[i-1][j-1] + triangle[i-1][j];
            }
            triangle.push_back(row);
        }
        return triangle;
    }
};