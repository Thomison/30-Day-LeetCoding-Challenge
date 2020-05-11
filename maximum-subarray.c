
static int max(int a, int b) {
    return a > b? a : b;
}

int maxSubArray(int* nums, int numsSize){
    int res = nums[0];      // array contains at least one number
    int dp[numsSize];
    for (int i = 0; i < numsSize; i++) {  // initialize
        dp[i] = 0;
    }
    for (int i = 0; i < numsSize; i++) {    // construct answer
        if (i == 0) {
            dp[i] = nums[i];
        } else {
            dp[i] = max(dp[i-1] + nums[i], nums[i]);
        }
        res = max(res, dp[i]);
    }
    return res;
}
