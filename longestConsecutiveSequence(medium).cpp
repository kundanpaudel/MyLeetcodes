class Solution {
public:
/*
    The trick here is to find out if any number in the provided vector is the first element of a sequence.
    For instance, if we have [1, 2, 3, 4, 100, 200] in the vector then we are going to check if n=1 then does
    n-1 exist in the vector. Similarly for n=2 if 2-1 exists in the vector and so on.

    If the n-1 element does not exist then we set length = 1 and then for every element we encounter after it
    we increment the length variable. But there can be multiple sequences in the given vector so we need to choose
    the longest one. Hence, we do longest = max(longest, length) where 'longest' variable will have previous sequence length
    and 'length' variable will have current sequence length.

    unordered_set creates unordered hash set where it only stores unique elements and omits duplicates. The search, insert, delete
    all take O(1) time in this data structure.
*/
    int longestConsecutive(vector<int>& nums) {
        int longest = 0;
        unordered_set<int> mySet(nums.begin(), nums.end());
        for(auto &n:mySet){
            if(mySet.count(n-1)==0){
                int length = 1;
                while(mySet.count(n+length)){
                    length++;
                }
                longest = max(longest, length);
            }
        }
        return longest;
    }
};