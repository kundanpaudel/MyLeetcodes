class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> findSum; // we return this vector
        unordered_map<int,int> hmap; // to store elements along with their index
        for(int i = 0; i < nums.size(); i++){ // iterate through the entire nums vector
            int complement = target - nums[i]; // calculate complement of the current element
            // .find() returns iterator pointing to the element if exists, otherwise it gives iterator pointing to .end().
            if(hmap.find(complement)!=hmap.end()){ // if complement exists
                findSum.push_back(hmap[complement]); // insert the index of complement
                findSum.push_back(i); // and insert index of current element
                return findSum;
            }else{  // if complement does not exist
                hmap.insert({nums[i], i}); // insert current element and index into hashmap
            }
        }
        return findSum;
    }
};

