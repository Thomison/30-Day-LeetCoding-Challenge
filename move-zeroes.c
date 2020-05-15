
/*
 * Given an array nums, write a function to move all 0's to the end of it while maintaining the relative order of the non-zero elements.
 */


void moveZeroes(int* nums, int numsSize){
    int i;      // for iterating the array
    int j;      // for keep tracking of non-zero elements
    for (i = 0, j = 0; i < numsSize; i++) {  // move the non-zero elements ahead
        if (nums[i] != 0) {
            nums[j++] = nums[i];
        }
    }
    for (; j < numsSize; j++) {     // fill zero to the end of the array
        nums[j] = 0;
    }
}
