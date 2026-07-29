class Solution {
public:
    string addBinary(string a, string b) {
        std::string result = "";
        int i = a.length() - 1;
        int j = b.length() - 1;
        int carry = 0;

        // Loop until both strings are exhausted and no carry remains
        while (i >= 0 || j >= 0 || carry > 0) {
            int sum = carry;
            
            if (i >= 0) {
                sum += a[i] - '0'; // Convert char to int
                i--;
            }
            if (j >= 0) {
                sum += b[j] - '0'; // Convert char to int
                j--;
            }
            
            // The current bit is the sum modulo 2
            result += std::to_string(sum % 2);
            
            // The new carry is the sum divided by 2
            carry = sum / 2;
        }

        // Since we appended from least to most significant bit, reverse the result
        std::reverse(result.begin(), result.end());
        
        return result;
    }
};