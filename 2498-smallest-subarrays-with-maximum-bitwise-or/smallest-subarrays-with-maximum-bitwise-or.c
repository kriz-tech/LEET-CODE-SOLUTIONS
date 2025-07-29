/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* smallestSubarrays(int* nums, int n, int* returnSize) {
    int* res = (int*)malloc(sizeof(int) * n);
    int last[32];

    for(int i = 0; i < 32; i++)
        last[i] = -1;

    for(int i = n - 1; i >= 0; i--){
        for(int b = 0; b < 32; b++){
            if((nums[i] >> b) & 1){
                last[b] = i;
            }
        }

    int max_len = 1;
    for(int b = 0; b < 32; b++){
        if(last[b] != -1){
            int dist = last[b] - i + 1;
            if(max_len < dist) max_len = dist;
        }
    }
    res[i] = max_len;
    }

    *returnSize = n;
    return res;
}