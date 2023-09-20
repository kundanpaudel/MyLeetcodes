class Solution {
public:
    int trap(vector<int>& height) {
        int i = 0; // First pointer starting from left
        int j = height.size()-1; // Second pointer starting from right
        int area = 0; // variable to store total area. We return this at the end.
        int maxLeft = height[i]; // Initial max left height
        int maxRight = height[j]; // Initial max right height

        while(i<j){ // Loop until i < j
        // Idea here is that the area will be equal to the difference of two consecutive heights.
        // Doing so can result in negative area which is not possible.
        // In order to avoid that we are taking max of each maxleft and maxright with the current height.
            if(maxLeft<=maxRight){  // Checking if max left is smaller
                i++; // If it is then move pointer one step
                maxLeft = max(maxLeft, height[i]); // Check which one is greater the max height from before or the current height and save it in maxleft.
                area += maxLeft - height[i]; // Area will be the larger height - smaller height. 
                // Since maxleft will always have larger value, the area will never be less than zero.
            }else{ // Same logic below but from the end of the provided array.
                j--;
                maxRight = max(maxRight, height[j]);
                area += maxRight - height[j];
            }
        }
        return area; // Return the area here.
    }
};