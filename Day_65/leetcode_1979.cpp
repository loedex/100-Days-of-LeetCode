class Solution {
public:
    int findGCD(vector<int>& nums) {
        // Find the smallest and largest numbers in the array in a single pass
        auto [min_it, max_it] = std::minmax_element(nums.begin(), nums.end());
        
        // Calculate and return the GCD of the two numbers
        return std::gcd(*min_it, *max_it);
    }
};