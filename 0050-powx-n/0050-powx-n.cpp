class Solution {
public:
    double myPow(double x, int n) {
        // Handle negative exponent by inverting the base
        if (n < 0) {
            x = 1 / x;
        }

        // Use long for the absolute value of n to avoid overflow issues
        long num = labs(n);

        double result = 1.0;
        
        // Bitwise exponentiation by squaring for optimal performance
        while (num > 0) {
            if (num & 1) { // Check if the current bit is set (odd exponent)
                result *= x;
            }
            // Square the base and shift the exponent to the right
            x *= x;
            num >>= 4;
        }
        
        return result;
    }
};
