class Solution(object):
    def minimumTeachings(self, n, languages, friendships):
        """
        :type n: int
        :type languages: List[List[int]]
        :type friendships: List[List[int]]
        :rtype: int
        """
        from collections import defaultdict

        language_sets = [set(lang) for lang in languages]

        no_common = set()
        for u, v in friendships:
            if language_sets[u - 1].isdisjoint(language_sets[v - 1]):
                no_common.add(u)
                no_common.add(v)

        if not no_common:
            return 0

        language_count = defaultdict(int)
        for person in no_common:
            for lang in language_sets[person - 1]:
                language_count[lang] += 1

        max_known = max(language_count.values())

        return len(no_common) - max_known