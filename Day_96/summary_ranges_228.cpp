class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        std::vector<std::string> res;
        int n = nums.size();
        if (n == 0) return res;
        
        long long start = nums[0];
        for (int i = 0; i < n; ++i) {
            if (i == n - 1 || (long long)nums[i] + 1 != nums[i + 1]) {
                if (start == nums[i]) {
                    res.push_back(std::to_string(start));
                } else {
                    res.push_back(std::to_string(start) + "->" + std::to_string(nums[i]));
                }
                if (i + 1 < n) {
                    start = nums[i + 1];
                }
            }
        }
        return res;
    }
};