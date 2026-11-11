class Solution {
public:
    vector<int> getRow(int rowIndex) {
       std::vector<int> row(rowIndex + 1, 0);
        row[0] = 1; // The 0th element is always 1

        for (int i = 1; i <= rowIndex; ++i) {
            // Traverse backwards to update in-place without losing previous values
            for (int j = i; j > 0; --j) {
                row[j] += row[j - 1];
            }
        }

        return row; 
    }
};