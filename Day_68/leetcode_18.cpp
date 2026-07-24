class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
     int n = nums.size();
        std::vector<std::vector<int>> ans;
        if (n < 4) return ans;

        // Step 1: Sort the array to use two-pointer technique
        std::sort(nums.begin(), nums.end());

        for (int i = 0; i < n - 3; ++i) {
            // Avoid duplicates for the first element
            if (i > 0 && nums[i] == nums[i - 1]) continue;

            // Pruning: smallest possible sum with current nums[i] exceeds target
            if ((long long)nums[i] + nums[i + 1] + nums[i + 2] + nums[i + 3] > target) break;
            // Pruning: largest possible sum with current nums[i] is smaller than target
            if ((long long)nums[i] + nums[n - 3] + nums[n - 2] + nums[n - 1] < target) continue;

            for (int j = i + 1; j < n - 2; ++j) {
                // Avoid duplicates for the second element
                if (j > i + 1 && nums[j] == nums[j - 1]) continue;

                // Sub-pruning for second loop
                if ((long long)nums[i] + nums[j] + nums[j + 1] + nums[j + 2] > target) break;
                if ((long long)nums[i] + nums[j] + nums[n - 2] + nums[n - 1] < target) continue;

                int left = j + 1;
                int right = n - 1;

                while (left < right) {
                    long long curr_sum = (long long)nums[i] + nums[j] + nums[left] + nums[right];

                    if (curr_sum == target) {
                        ans.push_back({nums[i], nums[j], nums[left], nums[right]});
                        left++;
                        right--;

                        // Skip duplicates for the third and fourth elements
                        while (left < right && nums[left] == nums[left - 1]) left++;
                        while (left < right && nums[right] == nums[right + 1]) right--;
                    } else if (curr_sum < target) {
                        left++;
                    } else {
                        right--;
                    }
                }
            }
        }
        return ans;
    }
};