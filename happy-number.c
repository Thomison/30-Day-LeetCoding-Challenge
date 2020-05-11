#include <stdbool.h>


int numSquareSum(int n) {
    int ret = 0;
    while (n != 0) {
        ret += (n % 10) * (n % 10);
        n /= 10;
    }
    return ret;
}

bool isHappy(int n) {
    int slow, fast;
    slow = fast = n;
    // circle encounter question
    do {
        slow = numSquareSum(slow);
        fast = numSquareSum(numSquareSum(fast));
    } while (slow != fast);
    
    return (slow == 1);
}

