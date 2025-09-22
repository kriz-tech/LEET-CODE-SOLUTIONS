/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* rearrangeArray(int* nums, int n, int* rs) {
    int* res = (int *) malloc(sizeof(int) * n);
    int pos_idx = 0, neg_idx = 1;

    for(int i = 0; i < n; i++){
        if(nums[i] >= 0){
            res[pos_idx] = nums[i];
            pos_idx += 2;
        }
        else
        {
            res[neg_idx] = nums[i];
            neg_idx += 2;
        }
    }

    *rs = n;
    return res;
}