class Solution {
public:
    string convertToTitle(int columnNumber) {
        std::string result = "";
        
        while (columnNumber > 0) {
            columnNumber--; // Shift from 1-indexed to 0-indexed
            char currentChar = 'A' + (columnNumber % 26);
            result.push_back(currentChar);
            columnNumber /= 26;
        }
        
        std::reverse(result.begin(), result.end());
        return result;
    }
};