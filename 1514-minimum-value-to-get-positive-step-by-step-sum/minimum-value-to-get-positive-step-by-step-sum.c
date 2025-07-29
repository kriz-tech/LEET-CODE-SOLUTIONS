int minStartValue(int* nums, int n) {
    int total = 0, min_sum = 0;

    for(int i = 0; i < n; i++){
        total += nums[i];
        min_sum = min_sum < total ? min_sum : total;
    }
    return 1 - min_sum;
}