class Solution
{
public:
    vector<int> dailyTemperatures(vector<int> &temperatures)
    {
        int size = temperatures.size(); // Saving the size of provided vector in a variable
        vector<int> results(size);      // This is the vector we return at the end
        stack<pair<int, int>> st;       // We store the index as well as the temperature of current day in the stack
        // The idea is to subtract the index of previous day from current day index and save the difference in
        // the previous day index.

        for (int i = 0; i < size; i++)
        {                                            // Loop until the end of the vector
            int currentDay = i;                      // The index is the current day number
            int currentTemperature = temperature[i]; // Temperature of the current day
            // Now, if the stack is not empty and the previous day temperature is less than current day
            while (!st.empty() && st.top().second < currentTemperature)
            {
                int previousDay = st.top().first;          // Save the previous day index
                int previousTemperature = st.top().second; // Save previous day temperature
                st.pop();                                  // Remove the previous day data
                // Save the distance between the smaller and larger temperature day
                result[previousDay] = currentDay - previousDay;
            }
            // If stack is empty or the current temperature is lower than previous temperature, we just push it into the stack
            st.push({currentDay, currentTemperature});
        }
        return result; // We return the final vector here
    }
};