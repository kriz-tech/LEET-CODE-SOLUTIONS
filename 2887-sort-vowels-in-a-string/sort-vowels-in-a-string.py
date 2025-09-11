class Solution(object):
    def sortVowels(self, s):
        """
        :type s: str
        :rtype: str
        """
        vowels_set = set("aeiouAEIOU")
        vowels = sorted([ch for ch in s if ch in vowels_set])

        res = []
        idx = 0

        for ch in s:
            if ch in vowels_set:
                res.append(vowels[idx])
                idx += 1
            else:
                res.append(ch)
        return "".join(res)
