int singleNumber(int* nums, int n) {
    int idx = 0;
    for(int i = 0; i < n; i++) idx ^= nums[i];
    return idx;
}