class Solution(object):
    def wordPattern(self, pattern, s):
        """
        :type pattern: str
        :type s: str
        :rtype: bool
        """
        p = s.split()
        return len(p) == len(pattern) and len(set(pattern)) == len(set(p)) == len(set(zip(p, pattern)))
        