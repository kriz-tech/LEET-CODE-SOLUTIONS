//Topdown Memorization...
int f[31] = {0, 1};
int fib(int n){
    if(n <= 1) return n;
    if(f[n] != 0) return f[n];
    f[n] = fib(n - 1) + fib(n - 2);
    return f[n];
}