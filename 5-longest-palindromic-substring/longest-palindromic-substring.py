class Solution:
    def longestPalindrome(self, s):
        if not s or len(s) == 1:
            return s
        long_palindrome = ""

        def finding(left, right):
            while left >= 0 and right < len(s) and s[left] == s[right]:
                left -= 1
                right += 1
            return s[left + 1:right]

        for i in range(len(s)):
            odd_palindrome = finding(i, i)
            even_palindrome = finding(i, i + 1)
            long_palindrome = max(long_palindrome, odd_palindrome, even_palindrome,key=len)

        return long_palindrome
