class Solution(object):
    def doesAliceWin(self, s):
        """
        :type s: str
        :rtype: bool
        """
        for ch in s:
            if ch in "aeiou":
                return True
        return False