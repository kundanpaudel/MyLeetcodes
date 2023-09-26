class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        int size = position.size(); // Since position and speed are both same size, we can use this for both
        vector<pair<int, double>> cars; // To store the position as well as the time taken to reach the target for each car

        for(int i = 0; i<size; i++){ // Iterating through both of the arrays
            double time = (double) (target-position[i])/speed[i]; // Calculating the time taken to reach the target for each car
            cars.push_back({position[i], time}); // Storing each car with their position and time taken to reach target.
        }
        // Sorting the vector by their position
        // Because technically, in the sorted vector, the smallest position reaches the target last
        sort(cars.begin(), cars.end()); 
        
        double maxTime = 0; // To store the maximum time taken for each fleet
        int fleet = 0; // To store the number of fleets

        // Iterating from the end of the sorted list because technically, the one closest to the target reach the target fast
        for(int i = size-1; i>=0; i++){ 
            double currentTime = cars[i].second; // The time for each car is stored at the second position of each index in the cars vector
            // If the time of arrival for current car is more than the maximum time of arrival so far
            // then it means we have a new fleet of cars arriving.
            if(currentTime > maxTime){ 
                maxTime = currentTime; // So, new max time will be the current time
                fleet++; // And since the current car is arriving later than the other car(s) so far, we increase the fleet number
            }
        }
        return fleet; // We return the number of fleet here.
    }
};