class Solution {
public:
    int findShortestSubArray(vector<int>& nums) {
        unordered_map<int, int> count;
        unordered_map<int, int> first_seen;
        unordered_map<int, int> last_seen;
        
        int degree = 0;
        
        // Populate the maps and find the overall degree
        for (int i = 0; i < nums.size(); ++i) {
            int num = nums[i];
            
            // Log the first time we see this number
            if (first_seen.count(num) == 0) {
                first_seen[num] = i;
            }
            
            // Continuously update the last time we've seen it
            last_seen[num] = i;
            
            // Increment frequency and update the maximum degree found so far
            count[num]++;
            degree = max(degree, count[num]);
        }
        
        int min_length = nums.size();
        
        // Check lengths of subarrays for all elements that match the maximum degree
        for (const auto& [num, freq] : count) {
            if (freq == degree) {
                int length = last_seen[num] - first_seen[num] + 1;
                min_length = min(min_length, length);
            }
        }
        
        return min_length;
    }
};