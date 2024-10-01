class Solution {
public:
    double myPow(double base, int exponent) {
        // If the exponent is negative, invert the base and make the exponent positive
        if (exponent < 0) {
            base = 1 / base;
        }

        // Use long to handle potential overflow for the absolute value of the exponent
        long absExponent = labs(exponent);

        double result = 1.0;
        
        // Exponentiation by squaring for optimal performance
        while (absExponent > 0) {
            // If the current bit of the exponent is set (odd exponent), multiply the result by the base
            if (absExponent & 1) {
                result *= base;
            }
            // Square the base for the next bit and right-shift the exponent
            base *= base;
            absExponent >>= 1; // Fixed the shift to 1 (not 4) for correct binary shifting
        }
        
        return result;
    }
};

