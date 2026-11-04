class Solution {
public:
    string convertToBase7(int num) {
        if (num == 0) return "0";
        
        bool isNegative = num < 0;
        num = std::abs(num);
        
        std::string result = "";
        while (num > 0) {
            result += std::to_string(num % 7);
            num /= 7;
        }
        
        if (isNegative) {
            result += "-";
        }
        
        std::reverse(result.begin(), result.end());
        return result;
    }
};