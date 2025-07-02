void rotate(int* nums, int n, int k) {
    k = k % n;

    int temp[n];
    for(int i = 0, j = n - k; i < k;i++, j++) temp[i] = nums[j];
    for(int i = k, j = 0; i < n; i++, j++) temp[i] = nums[j];
    for(int i = 0; i < n; i++) nums[i] = temp[i];
}