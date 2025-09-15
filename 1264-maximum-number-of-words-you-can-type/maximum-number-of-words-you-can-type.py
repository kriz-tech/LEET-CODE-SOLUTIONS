class Solution(object):
    def canBeTypedWords(self, text, bl):
        """
        :type text: str
        :type brokenLetters: str
        :rtype: int
        """
        broken = set(bl)
        words = text.split()
        count = 0
        for word in words:
            if not (set(word) & broken):
                count += 1
        return count