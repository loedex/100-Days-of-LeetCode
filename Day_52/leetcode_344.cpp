class Solution {
public:
    void reverseString(vector<char>& s) {
        int left = 0;
        int right = s.size() - 1;
        
        while (left < right) {
            // Swap characters at the two pointers
            swap(s[left], s[right]);
            
            // Move pointers towards the middle
            left++;
            right--;
        }
    }
};