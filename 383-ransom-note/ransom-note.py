class Solution(object):
    def canConstruct(self, r, m):
        """
        :type ransomNote: str
        :type magazine: str
        :rtype: bool
        """
        m = list(m)
        for letter in r:
            if letter in m:
                m.remove(letter)
            else:
                return False
        return True