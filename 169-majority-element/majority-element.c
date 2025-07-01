int majorityElement(int* nums, int n) {
    int flag = nums[0];
    int k  = 1;
    for(int i = 1; i < n; i++)
    {
        if(flag == nums[i]) k++;
        else
        {
            k--;
            if(k == 0)
            {
                flag = nums[i];
                k = 1;
            }
        }
    }
    return flag;

}