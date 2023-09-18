class Solution
{
public:
    bool containsDuplicate(vector<int> &nums)
    {
        unordered_map<int, int> hmap; // Create a map to store both the numbers and their frequencies.
        for (int i = 0; i < nums.size(); i++)
        {                    // Iterate through the given vector.
            hmap[nums[i]]++; // Save the numbers and their frequency in the map, automatically incrementing it.
        }
        for (auto x : nums)
        { // Iterate through the given array.
            if (hmap[x] > 1)
            { // If frequency is more than one.
                return true;
            }
        }
        return false;
    }
};

/*
    --ALTERNATE SOLUTION--
class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_map<int, int> hmap;
        for(auto num:nums){
            hmap[num]++;
            if(hmap[num]>1){
                return true;
            }
        }
        return false;
    }
};
*/