int maximumDifference(int* nums, int n) {
    int max_difference = -1;
    for(int i = 0; i < n - 1; i++)
    {
        for(int j = i + 1; j < n; j++)
        {
            if(nums[i] < nums[j])
            {
                int temp = nums[j] - nums[i];
                if(temp > max_difference) max_difference = temp;
            }
        }
    }
    return max_difference;
}