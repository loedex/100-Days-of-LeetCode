class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        // Map to store the value and its most recent index
        std::unordered_map<int, int> numMap;
        
        for (int i = 0; i < nums.size(); ++i) {
            // Check if the number exists in the map
            if (numMap.count(nums[i])) {
                // Check if the distance between indices is <= k
                if (i - numMap[nums[i]] <= k) {
                    return true;
                }
            }
            // Update the map with the current index
            numMap[nums[i]] = i;
        }
        
        // If we finish the loop without finding any, return false
        return false;
    }
};