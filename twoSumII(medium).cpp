class Solution {
public:
/*
    The trick here is to use two pointers to add elements from the given vectors.
    If the sum is smaller than target then increase the starting pointer.
    If sum is greater than target, decrease the end pointer.
    If the sum is exactly equal to the target, push (or return) the result;
    We can do this because the given array/vector is already sorted in ascending order.
*/
    vector<int> twoSum(vector<int>& numbers, int target) {
        vector<int> result;
        int i = 0;
        int j = numbers.size()-1;
        while(i<j){
            if((numbers[i]+numbers[j]) > target){
                j--;
            }
            else if((numbers[i]+numbers[j]) < target){
                i++;
            }else{
                result.push_back(i+1);
                result.push_back(j+1);
                break;
            }
        }
        return result;
    }
};