class Solution {
public:
    int nextGreaterElement(int n) {
        string digits = to_string(n);
        int len = digits.size();
        int i = len - 2;
        while (i >= 0 && digits[i] >= digits[i + 1]) {
            i--;
        }
        if (i < 0) return -1;
        int j = len - 1;
        while (digits[j] <= digits[i]) {
            j--;
        }
        swap(digits[i], digits[j]);
        reverse(digits.begin() + i + 1, digits.end());
        long result = stol(digits);
        return (result > INT_MAX) ? -1 : result;
    }
};
