/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* replaceElements(int* arr, int n, int* returnSize) {
    int* res = (int *)malloc(n * sizeof(int));

    int max_right = -1;
    for(int i = n - 1; i >= 0; i--)
    {
        res[i] = max_right;
        if(max_right < arr[i])
        {
            max_right = arr[i];
        }
    }
    *returnSize = n;
    return res;
}