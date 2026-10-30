class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if (strs.empty()) return "";

        // Sort the strings lexicographically
        std::sort(strs.begin(), strs.end());

        // The common prefix of the whole array must be common to 
        // the first and the last string after sorting.
        std::string first = strs.front();
        std::string last = strs.back();
        
        int minLength = std::min(first.length(), last.length());
        int i = 0;
        
        while (i < minLength && first[i] == last[i]) {
            i++;
        }

        return first.substr(0, i);
    }
};