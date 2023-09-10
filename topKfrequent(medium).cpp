class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<int> results;
        unordered_map<int, int> hmap;
        for(auto num:nums){
            hmap[num]++;
        }

        vector<vector<int>> bucket(nums.size()+1);
        for(auto it:hmap){
            bucket[it.first].push_back(it.second);
        }

        for(int i = bucket.size()-1; i>=0 && results.size() < k; i--){
            for(int num:bucket[i]){
                results.push_back(num);
                if(results.size()==k){
                    break;
                }
            }
        }

        return results;
    }
};