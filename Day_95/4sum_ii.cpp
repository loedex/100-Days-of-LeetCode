class Solution {
public:
    int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3, vector<int>& nums4) {
       std::unordered_map<int, int> sumCount;
        
        // Step 1: Store frequencies of sums from nums1 and nums2
        for (int a : nums1) {
            for (int b : nums2) {
                sumCount[a + b]++;
            }
        }
        
        int totalTuples = 0;
        
        // Step 2: Check complements from nums3 and nums4
        for (int c : nums3) {
            for (int d : nums4) {
                int target = -(c + d);
                auto it = sumCount.find(target);
                if (it != sumCount.end()) {
                    totalTuples += it->second;
                }
            }
        }
        
        return totalTuples; 
    }
};