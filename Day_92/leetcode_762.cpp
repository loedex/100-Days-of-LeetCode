class Solution {
public:
    int countPrimeSetBits(int left, int right) {
       // Since right <= 10^6, the maximum number of set bits for any integer
        // in this range is 20 (since 2^20 > 10^6).
        // Primes up to 20 are: 2, 3, 5, 7, 11, 13, 17, 19.
        std::unordered_set<int> primes = {2, 3, 5, 7, 11, 13, 17, 19};
        
        int count = 0;
        for (int num = left; num <= right; ++num) {
            // std::popcount is available in C++20 (or we can use __builtin_popcount)
            int setBits = __builtin_popcount(num);
            if (primes.count(setBits)) {
                count++;
            }
        }
        
        return count; 
    }
};