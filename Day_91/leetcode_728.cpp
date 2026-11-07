class Solution {
public:
    vector<int> selfDividingNumbers(int left, int right) {
        std::vector<int> result;
        
        for (int num = left; num <= right; ++num) {
            if (isSelfDividing(num)) {
                result.push_back(num);
            }
        }
        
        return result;
    }

private:
    bool isSelfDividing(int n) {
        int temp = n;
        while (temp > 0) {
            int digit = temp % 10;
            // A self-dividing number cannot contain zero, 
            // and the number must be divisible by each of its digits.
            if (digit == 0 || n % digit != 0) {
                return false;
            }
            temp /= 10;
        }
        return true;
    }
};