/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* nextGreaterElements(int* nums, int n, int* rs) {
    int* res = malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        res[i] = -1; 
        for (int j = 1; j < n; j++) {
            if (nums[(i + j) % n] > nums[i]) {
                res[i] = nums[(i + j) % n];
                break;
            }
        }
    }
    *rs = n;
    return res;
}

