class Solution(object):
    def divide(self, dividend, divisor):
        """
        :type dividend: int
        :type divisor: int
        :rtype: int
        """
        INT_MAX, INT_MIN = 2**31 - 1, -2**31
        if dividend == INT_MIN and divisor == -1:
            return INT_MAX
        sign = -1 if(dividend < 0) ^ (divisor < 0) else 1
        dividend, divisor = abs(dividend), abs(divisor)
        res = 0
        while dividend >= divisor:
            temp, mul = divisor, 1
            while dividend >= (temp << 1):
                temp <<= 1
                mul <<= 1
            dividend -= temp
            res += mul
        
        return sign * res