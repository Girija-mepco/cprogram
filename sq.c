int mySqrt(int x) {
    // Handle edge cases where x is 0 or 1
    if (x < 2) {
        return x;
    }
    
    int left = 2;
    int right = x / 2;
    
    while (left <= right) {
        int mid = left + (right - left) / 2;
        
        // Use division (x / mid) instead of (mid * mid) 
        // to prevent integer overflow errors
        if (mid == x / mid) {
            return mid;
        } else if (mid > x / mid) {
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }
    
    return right;
}
