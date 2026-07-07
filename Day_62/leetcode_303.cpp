class NumArray {
private:
    vector<int> prefixSum;

public:
    NumArray(vector<int>& nums) {
        int n = nums.size();
        // Allocate space for n + 1 elements, initialized to 0
        prefixSum.resize(n + 1, 0);
        
        // Build the prefix sum array
        for (int i = 0; i < n; i++) {
            prefixSum[i + 1] = prefixSum[i] + nums[i];
        }
    }