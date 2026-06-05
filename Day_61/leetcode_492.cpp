class Solution {
public:
    vector<int> constructRectangle(int area) {
        int w = std::sqrt(area);
        
        // Decrement w until we find a value that perfectly divides the area
        while (area % w != 0) {
            w--;
        }
        
        // Once found, L = area / w. Since we started from sqrt(area) downwards, L >= w
        int l = area / w;
        
        return {l, w};
    }
};