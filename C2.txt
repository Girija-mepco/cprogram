#include <stdbool.h>

bool judgeSquareSum(int c) {
    // Two pointers: one starts at 0, the other at floor(sqrt(c))
    long left = 0;
    long right = 0;
    
    // Find the floor square root of c manually using our previous logic
    // or a fast truncation loop to avoid built-in functions
    long i = 0;
    while (i * i <= c) {
        right = i;
        i++;
    }
    
    while (left <= right) {
        long current_sum = left * left + right * right;
        
        if (current_sum == c) {
            return true;
        } else if (current_sum < c) {
            left++;     // Sum is too small, increase the lower bound
        } else {
            right--;    // Sum is too large, decrease the upper bound
        }
    }
    
    return false;
}

