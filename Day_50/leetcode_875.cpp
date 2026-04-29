class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
          int low = 1, high = *max_element(piles.begin(), piles.end());
        while (low < high) {
            int mid = low + (high - low) / 2;
            long long totalHours = 0;
            for (int p : piles) {
                // Calculate hours needed for this pile with speed mid
                totalHours += (p + mid - 1LL) / mid;
            }
            if (totalHours <= h) {
                // Koko can finish in time, try a smaller speed
                high = mid;
            } else {
                // Too slow, need a larger speed
                low = mid + 1;
            }
        }
        return low;
    }
};