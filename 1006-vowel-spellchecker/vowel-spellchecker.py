class Solution(object):
    def spellchecker(self, wordlist, queries):
        """
        :type wordlist: List[str]
        :type queries: List[str]
        :rtype: List[str]
        """
        word_set = set(wordlist)  # For exact match
        case_map = {}  # Case-insensitive map
        vowel_map = {}  # Vowel error map

        def devowel(word):
            return ''.join('*' if ch in 'aeiou' else ch for ch in word)

        # Build maps
        for word in wordlist:
            lower = word.lower()
            case_map.setdefault(lower, word)
            vowel_map.setdefault(devowel(lower), word)

        res = []
        for query in queries:
            if query in word_set:
                res.append(query)
            elif query.lower() in case_map:
                res.append(case_map[query.lower()])
            elif devowel(query.lower()) in vowel_map:
                res.append(vowel_map[devowel(query.lower())])
            else:
                res.append("")
        return res