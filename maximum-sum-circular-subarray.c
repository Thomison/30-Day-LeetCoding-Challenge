#include <limits.h>

int max(int a, int b) { return a > b ? a : b;}
int min(int a, int b) { return a < b ? a : b;}

int maxSubarraySum(int *A, int ASize) {
    int max_so_far = INT_MIN;
    int max_ending_here = 0;
    for (int i = 0; i < ASize; i++) {
        max_ending_here += A[i];
        max_so_far = max(max_so_far, max_ending_here);
        max_ending_here = max(max_ending_here, 0);
    }
    return max_so_far;
}

int maxSubarraySumCircular_1(int* A, int ASize){
    int s1 = maxSubarraySum(A, ASize);
    int s2 = 0;
    for (int i = 0; i < ASize; i++) {
        s2 += A[i];
        A[i] = -A[i];
    }
    s2 += maxSubarraySum(A, ASize);
    if(s1 < 0) return s1;
    else return max(s1, s2);
}

int maxSubarraySumCircular_2(int* A, int ASize){
    int max_sum = INT_MIN, min_sum = INT_MAX;
    int max_cur = 0, min_cur = 0, total = 0;
    for (int i = 0; i < ASize; i++) {
        // get the sum of array.
        total += A[i];
        // find the max sum of subarray.
        max_cur += A[i];
        max_sum = max(max_sum, max_cur);
        max_cur = max(max_cur, 0);
        // find the min sum of subarray. 
        min_cur += A[i];
        min_sum = min(min_sum, min_cur);
        min_cur = min(min_cur, 0);
    }
    return max_sum < 0 ? max_sum : max(max_sum, total - min_sum);
}
