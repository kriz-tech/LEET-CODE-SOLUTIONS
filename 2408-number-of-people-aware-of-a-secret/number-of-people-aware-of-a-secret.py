class Solution(object):
    def peopleAwareOfSecret(self, n, delay, forget):
        """
        :type n: int
        :type delay: int
        :type forget: int
        :rtype: int
        """
        MOD = 10 ** 9 + 7
        dp = [0] * (n + 1)
        dp[1] = 1  # On day 1, one person knows the secret
    
        for day in range(1, n + 1):
            if dp[day] == 0:
                continue
        
        # The day this person starts sharing the secret
            start_share = day + delay
        # The day this person forgets the secret
            forget_day = day + forget
        
        # They share the secret from start_share to forget_day - 1
            for future_day in range(start_share, min(forget_day, n + 1)):
                dp[future_day] = (dp[future_day] + dp[day]) % MOD
    
    # At the end, sum all people who still know the secret
        result = 0
        for day in range(n - forget + 1, n + 1):
            if day >= 1:
                result = (result + dp[day]) % MOD
            
        return result