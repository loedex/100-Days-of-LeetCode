class Solution {
public:
    string toHex(int num) {
        if (num == 0) return "0";
        
        const char* hexChars = "0123456789abcdef";
        std::string result = "";
        
        // Cast to unsigned int to correctly handle negative numbers via two's complement
        unsigned int n = num;
        
        while (n > 0) {
            int remainder = n & 15; // Extract the last 4 bits
            result += hexChars[remainder];
            n >>= 4;                // Right shift by 4 bits
        }
        
        std::reverse(result.begin(), result.end());
        return result;
    }
};