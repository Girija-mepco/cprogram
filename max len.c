#include <string.h>

// Helper macro to find the maximum of two numbers
#define MAX(a, b) ((a) > (b) ? (a) : (b))

int findLength(int* nums1, int nums1Size, int* nums2, int nums2Size) {
    // dp[j] will store the length of the longest common suffix 
    // ending at nums1[i-1] and nums2[j-1]
    int dp[nums2Size + 1];
    memset(dp, 0, sizeof(dp));
    
    int max_len = 0;
    
    // Iterate through each element of nums1
    for (int i = 1; i <= nums1Size; i++) {
        // Iterate backwards through nums2 to reuse the 1D dp array safely
        for (int j = nums2Size; j >= 1; j--) {
            if (nums1[i - 1] == nums2[j - 1]) {
                dp[j] = dp[j - 1] + 1;
                max_len = MAX(max_len, dp[j]);
            } else {
                dp[j] = 0; // Reset if the contiguous sequence breaks
            }
        }
    }
    
    return max_len;
}

