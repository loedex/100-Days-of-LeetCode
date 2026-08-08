class Solution {
public:
    int numIdenticalPairs(vector<int>& nums) {
        std::unordered_map<int, int> freq;
        int good_pairs = 0;
        
        for (int num : nums) {
            good_pairs += freq[num];
            freq[num]++;
        }
        
        return good_pairs;
    }
};