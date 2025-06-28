/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* nextGreaterElements(int* nums, int n, int* rs) {
    int *res = (int*)malloc(n * sizeof(int));

    int* double_nums = (int*)malloc(2 * n * sizeof(int));

    for(int i = 0; i < 2 * n; i++)
    {
        double_nums[i] = nums[i % n];
    }
    for(int i = 0; i < n; i++)
    {
        res[i] = -1;
        for(int j = i + 1; j < 2 * n; j++)
        {
            if(nums[i] < double_nums[j])
            {
                res[i] = double_nums[j];
                break;
            }
        }
    }

    *rs = n;
    return res;
}
