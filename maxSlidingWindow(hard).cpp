class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> results; // To store the returning max numbers array
        deque<int> dq; // To store the numbers in decreasing order. Also O(1) time to add or remove from front/back

        int i = 0, j = 0; // Initializing two pointers
        while(j<nums.size()){ // Looping until we reach end of nums vector
            // While deque is not empty and the back of the deque is less than current nums element.
            // Note: we are only storing indices in our deque not the numbers of nums vector themselves.
            while(!dq.empty() && nums[dq.back()] < nums[j]){
                dq.pop_back(); // We are popping the back of dq since we need decreasing queue.
            }

            if(j+1 >= k){ // If we have a valid window then
                results.push_back(nums[dq.front()]); // We push the max element of the window to our vector
                i++; // Then we move the left pointer by one step.
            }
            j++; // We then also ove the right pointer.

            if(i>dq.front()){ // If the left index has passed the largest elements index then
                dq.pop_front(); // Get rid of the largest element as it is not in the window anymore.
            }

        }
        return results; // Return the vector with max elements in them.
    }