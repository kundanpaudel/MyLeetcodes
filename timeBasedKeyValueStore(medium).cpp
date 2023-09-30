class TimeMap
{
private:
    // We are using hashmap for this problem to store the provided data
    // The benefit of doing this is search time for hashmap is O(1)
    unordered_map<string, vector<pair<string, int>>> hMap;
    // In this map we are storing values in the form [key [value, timestamp]]
public:
    TimeMap()
    {
    }

    void set(string key, string value, int timestamp)
    {
        // Set is just inserting the value into the hashmap
        // In this case we need to store values inside the vector of the hashmap
        // That's why we are using push_back
        hMap[key].push_back({value, timestamp});
    }

    string get(string key, int timestamp)
    {
        // First we search for key in hashmap, if we dont find it we return empty string
        if (hMap.find(key) == hMap.end())
        {
            return "";
        }

        // Now we perform binary search on the 'key' index
        int left = 0, right = hMap[key].size();
        while (left <= right)
        {
            int midPoint = left + (right - left) / 2; // Calculating the midpoint of the vector at 'key'
            // Now we check if at the medpoint of the vector in 'key' index has a timestamp less than the
            // provided timestamp
            if (hMap[key][midPoint].second < timestamp)
            {
                left = midPoint + 1; // If yes then we move the left pointer to the midPoint+1 location
            }
            // If the midpoint timestamp in the vector is larger than the provided timestamp for get
            else if (hMap[key][midPoint].second > timestamp)
            {
                // That means we move the right pointer
                right = midPoint - 1;
            }
            // Otherwise it means the midpoint timestamp is equal to passed timestamp and we return
            // the value it represents.
            else
            {
                return hMap[key][midPoint].first;
            }
        }
        // At the end of the loop the right pointer will point at the highest number right before the
        // passed timestamp in the function
        // So in case we cannot find the provided timestamp, we return the previous highest value
        if (right >= 0)
        {                                  // If the right pointer is at the first element or any other, basically if it exists
            return hMap[key][right].first; // Then return the value it represents
        }
        return ""; // If none of the conditions pass then return empty string.
    }
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */