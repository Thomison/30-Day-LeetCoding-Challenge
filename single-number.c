

int singleNumber(int* nums, int numsSize){
    int ret = 0; 
    int i = 0;
    for (; i < numsSize; i++) {
        ret ^= nums[i];
    }
    return ret;
}
