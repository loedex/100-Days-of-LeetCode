#include <string>
#include <unordered_map>
#include <vector>
#include <algorithm>

using namespace std;

class TimeMap {
private:
    // Maps a string key to a vector of pairs (timestamp, value)
    unordered_map<string, vector<pair<int, string>>> store;

public:
    TimeMap() {
        // Initialization can be left empty
    }
    
    void set(string key, string value, int timestamp) {
        // Because timestamps are strictly increasing, we can just push to the back.
        // Time Complexity: O(1) amortized
        store[key].push_back({timestamp, value});
    }
    
    string get(string key, int timestamp) {
        // If the key doesn't exist at all, return an empty string
        if (store.find(key) == store.end()) {
            return "";
        }
        
        const auto& values = store[key];
        
        // Use upper_bound to find the first element with a timestamp strictly greater than 'timestamp'
        auto it = upper_bound(values.begin(), values.end(), timestamp, 
            [](int val, const pair<int, string>& p) {
                return val < p.first;
            });
        
        // If 'it' points to the beginning, it means all timestamps are strictly greater than the target
        if (it == values.begin()) {
            return "";
        }
        
        // Go back one step to get the largest timestamp that is <= the target timestamp
        return prev(it)->second;
    }
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */