class Solution(object):
    def makeFancyString(self, s):
        """
        :type s: str
        :rtype: str
        """
        res = []

        for letter in s:
            if len(res) >= 2 and res[-1] == res[-2] == letter:
                continue
            res.append(letter)

        return ''.join(res)
        