#include <vector>
#include <algorithm>

class Solution {
public:
    int smallestRangeI(std::vector<int>& nums, int k) {
        // Find the minimum and maximum elements in a single pass
        auto [min_it, max_it] = std::minmax_element(nums.begin(), nums.end());
        int min_val = *min_it;
        int max_val = *max_it;
        
        // Calculate the minimized difference
        int potential_score = max_val - min_val - 2 * k;
        
        // If the score is negative or zero, it means we can make the difference 0
        return std::max(0, potential_score);
    }
};