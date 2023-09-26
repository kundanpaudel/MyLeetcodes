class Solution
{
public:
    int minEatingSpeed(vector<int> &piles, int h)
    {
        int lowSpeed = 1;  // The lowest speed koko can eat is 1 banana per hour
        int highSpeed = 0; // We don't know the highest speed yet, so we set it to zero
        for (auto p : piles)
        {   // We iterate through the given list
            // And find out the highest pile which is equal to highest speed koko can eat
            highSpeed = max(p, highSpeed);
        }
        // We don't know the minimum speed yet, so we save the highest speed value
        // and keep updating whenever we find smaller speed
        int minSpeed = highSpeed;

        // Now, we loop until the lowest speed is less or equal to the highest speed koko can eat
        while (lowSpeed <= highSpeed)
        {
            int midSpeed = lowSpeed + (highSpeed - lowSpeed) / 2; // Calculate the mid speed for binary search
            // This is where we store total hours taken to eat all the bananas
            // at midSpeed.
            long int totalHours = 0;
            for (auto p : piles)
            { // We looop through the list again
                // And calculate the total hours taken to eat at midSpeed
                totalHours += ceil((double)p / midSpeed);
            }
            if (totalHours <= h)
            {                                       // If the total hours taken is less than or equal to the target hours
                minSpeed = min(minSpeed, midSpeed); // We update the minSpeed with the new speed (midSpeed)
                highSpeed = midSpeed - 1;           // Then we move the highSpeed pointer for binary search
            }
            else
            {                            // If the hours taken is larger than provided target hour
                lowSpeed = midSpeed + 1; // Move the lowSpeed pointer for binary search
            }
        }
        return minSpeed; // At the end return the minimum speed calculated
    }
};