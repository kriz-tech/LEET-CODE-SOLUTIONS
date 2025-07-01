int trap(int* h, int n) {
    int res = 0, lmax[n], rmax[n];
    lmax[0] = h[0];
    for(int i = 1; i < n; i++) lmax[i] = fmax(lmax[i - 1], h[i]);
    rmax[n - 1] = h[n - 1];
    for(int i = n - 2; i >= 0; i--) rmax[i] = fmax(rmax[i + 1], h[i]);
    for(int i = 0; i < n; i++) res += fmin(lmax[i],rmax[i]) - h[i];
    return res;
}