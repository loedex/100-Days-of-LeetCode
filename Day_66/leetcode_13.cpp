class Solution {
public:
    int romanToInt(string s) {
        // Map to store the values of Roman numerals
        unordered_map<char, int> roman = {
            {'I', 1}, {'V', 5}, {'X', 10},
            {'L', 50}, {'C', 100}, {'D', 500},
            {'M', 1000}
        };
        
        int total = 0;
        int n = s.length();
        
        for (int i = 0; i < n; i++) {
            // If the current numeral is smaller than the next one, subtract it (e.g., IV, IX)
            if (i < n - 1 && roman[s[i]] < roman[s[i + 1]]) {
                total -= roman[s[i]];
            } 
            // Otherwise, add it (e.g., VI, CX)
            else {
                total += roman[s[i]];
            }
        }
        
        return total;
    }
};