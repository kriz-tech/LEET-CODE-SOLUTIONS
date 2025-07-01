/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* runningSum(int* nums, int n, int* returnSize) {
    int *res = (int*)malloc(n * sizeof(int));
    int sum = 0;
    for(int i = 0; i < n; i++)
    {
        sum += nums[i];
        res[i] = sum;
    }
    *returnSize = n;
    return res;
}