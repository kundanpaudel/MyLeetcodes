class Solution
{
public:
    vector<int> topKFrequent(vector<int> &nums, int k)
    {
        vector<int> results;          // This is the vector we return at the end.
        unordered_map<int, int> hmap; // We are using this map to store the elements from array as well as calculate the frequency.

        // This loop basically takes each element (num) from the array nums.
        // 'auto' is c++ extension basically which assigns appropriate type for the elememts in the nums vector.
        for (auto num : nums)
        {
            hmap[num]++; // This counts and stores the frequency of the numbers assigning to them.
        }

        // We are using bucket sort below, so we need a bucket to store elements.
        // We are creating nested vector as our bucket. The frequency of the elements will be out index and the vector of numbers that
        // match the frequency will be what we need at the very end.
        // The bucket size is nums.size()+1 here because c++ indexing goes starts from zero. So if we have array [1,1,1,1,1] then we
        // have indices 0,1,2,3,4 for it. However the number 1 repeats 5 times, so nums.size()+1 gives us the index 5 or max index.
        vector<vector<int>> bucket(nums.size() + 1);

        // This is the loop to iterate through out hashmap.
        for (auto it : hmap)
        {
            // Now we are storing in our bucket at index frequency (it.second gives us the frequency stored in hashmap) the numbers
            // that match the frequency (it.first gives us the numbers that match the frequency from it.second).
            bucket[it.second].push_back(it.first);
        }

        // In this loop we are copying the numbers with highest frequency to results vector.
        // Since the highest frequency will be at the end, we are starting from the end of the bucket.
        // The index we are starting from is bucket.size()-1 because again, c++ indexing starts from zero so, when we create
        // an array or vector of size n we have minimum index 0 and maximum index (n-1).
        // One of our condition is results.size()<k because if k is 1 we need to give only one max freq number, which is index 0.
        for (int i = bucket.size() - 1; i >= 0 && results.size() < k; i--)
        {
            // In the following loop we are iterating through the bucket. Note that there is already an index i used for bucket[i] so,
            // it will return the number that is saved at that index. Also note that the index here is the frequency of the number.
            for (auto num : bucket[i])
            {
                results.push_back(num); // Basically just pushing the max numbers into our vector that we are returning.
                if (results.size() == k)
                { // This is the conditional that we implemented so that the loop only runs until the vector size is equal k.
                    break;
                }
            }
        }

        return results; // Return result vector here.
    }
};