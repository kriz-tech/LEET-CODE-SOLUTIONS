class Solution:
    def productQueries(self, n: int, queries: List[List[int]]) -> List[int]:
        MOD = 10 ** 9 + 7
        powers = []
        temp = n
        while temp:
            low = temp & -temp
            powers.append(low)
            temp -= low

        prefix = []
        prod = 1

        for p in powers:
            prod = (prod * p) % MOD
            prefix.append(prod)

        inv = pow
        answers = []
        for l, r in queries:
            if l == 0:
                answers.append(prefix[r])
            else:
                inv_val = inv(prefix[l-1], MOD - 2, MOD)
                answers.append(prefix[r] * inv_val % MOD)
        return answers