class Solution {
public:
    string addStrings(string num1, string num2) {
        std::string result = "";
        int i = num1.length() - 1;
        int j = num2.length() - 1;
        int carry = 0;

        while (i >= 0 || j >= 0 || carry > 0) {
            int sum = carry;

            if (i >= 0) {
                sum += num1[i] - '0';
                i--;
            }
            if (j >= 0) {
                sum += num2[j] - '0';
                j--;
            }

            carry = sum / 10;
            result.push_back((sum % 10) + '0');
        }

        std::reverse(result.begin(), result.end());
        return result;
    }
};