/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* nextGreaterElements(int* nums, int n, int* rs) {
    int* res = (int*)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        res[i] = -1; 
        for (int j = 1; j < n; j++) {
            int idx = (i + j) % n;
            if (nums[idx] > nums[i]) {
                res[i] = nums[idx];
                break;
            }
        }
    }

    *rs = n;
    return res;
}
