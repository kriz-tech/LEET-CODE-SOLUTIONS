class Solution:
    def maxFreqSum(self, s: str) -> int:
        vowels = set("aeiou")
        count = Counter(s)

        max_vowel = max((count[ch] for ch in vowels if ch in count), default=0)
        max_cons  = max((count[ch] for ch in count if ch not in vowels), default=0)

        return max_vowel + max_cons