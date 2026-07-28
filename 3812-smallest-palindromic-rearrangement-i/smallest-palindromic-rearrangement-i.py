class Solution(object):
    def smallestPalindrome(self, s):
        """
        :type s: str
        :rtype: str
        """
        freq = [0] * 26
        for ch in s:
            freq[ord(ch) - ord('a')] += 1
        
        left = []
        middle = ""

        for i in range(26):
            left.append(chr(i + ord('a')) * (freq[i] // 2))

            if freq[i] % 2 != 0:
                middle = chr(i + ord('a'))
        left = "".join(left)
        right = left[::-1]

        return left + middle + right
        