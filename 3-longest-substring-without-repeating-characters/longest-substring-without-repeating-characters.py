class Solution(object):
    def lengthOfLongestSubstring(self, s):
        """
        :type s: str
        :rtype: int
        """
        res = 0
        l = 0
        sub_string = set()

        for r in range(len(s)):
            while s[r] in sub_string:
                sub_string.remove(s[l])
                l += 1
            
            sub_string.add(s[r])
            res = max(res, r - l + 1)
        return res