class Solution {
public:
    int maxLength(vector<int>& nums) {
       int n = static_cast<int>(nums.size());
        int primes[4] = {2, 3, 5, 7};
        int ans = 1;

        for (int i = 0; i < n; ++i) {
            for (int j = i; j < n; ++j) {
                bool ok = true;
                for (int p : primes) {
                    int mn = INT_MAX, mx = 0, sum = 0, cnt = 0;
                    for (int k = i; k <= j; ++k) {
                        int x = nums[k];
                        int expP = 0;
                        while (x % p == 0) {
                            ++expP;
                            x /= p;
                        }
                        if (expP > 0) {
                            ++cnt;
                            sum += expP;
                            mn = min(mn, expP);
                            mx = max(mx, expP);
                        }
                    }
                    int effectiveMin = (cnt == (j - i + 1)) ? mn : 0;
                    if (mx + effectiveMin != sum) {
                        ok = false;
                        break;
                    }
                }
                if (ok) {
                    ans = max(ans, j - i + 1);
                }
            }
        }
        return ans;
    }
};