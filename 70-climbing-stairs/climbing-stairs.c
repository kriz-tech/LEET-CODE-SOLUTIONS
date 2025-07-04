int climbStairs(int n) {
    if(n <= 1) return n;
    int curr = 0, next = 1;
    for(int i = 0; i < n; i++)
    {
        int temp = curr + next;
        curr = next;
        next = temp;
    }
    return next;
}