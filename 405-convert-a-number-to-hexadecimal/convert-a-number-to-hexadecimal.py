class Solution(object):
    def toHex(self, num):
        if num == 0:
            return "0"

        hex_chars = "0123456789abcdef"
        result = ""

    # For negative numbers, convert to 32-bit unsigned value
        num &= 0xFFFFFFFF

        while num > 0:
            digit = num % 16
            result = hex_chars[digit] + result
            num //= 16

        return result

        