#include <vector>

class Solution {
public:
    int oddCells(int m, int n, std::vector<std::vector<int>>& indices) {
        // Track the count of increments for each row and column
        std::vector<int> rowCounts(m, 0);
        std::vector<int> colCounts(n, 0);
        
        // Populate the frequency arrays
        for (const auto& index : indices) {
            rowCounts[index[0]]++;
            colCounts[index[1]]++;
        }
        
        // Count how many rows and columns have an odd number of increments
        int oddRows = 0;
        for (int i = 0; i < m; ++i) {
            if (rowCounts[i] % 2 != 0) {
                oddRows++;
            }
        }
        
        int oddCols = 0;
        for (int j = 0; j < n; ++j) {
            if (colCounts[j] % 2 != 0) {
                oddCols++;
            }
        }
        
        // Apply the counting formula
        return (oddRows * (n - oddCols)) + ((m - oddRows) * oddCols);
    }
};