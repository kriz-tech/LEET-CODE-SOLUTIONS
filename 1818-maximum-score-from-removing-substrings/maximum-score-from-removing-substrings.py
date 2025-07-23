class Solution(object):
    def maximumGain(self, s, x, y):
        """
        :type s: str
        :type x: int
        :type y: int
        :rtype: int
        """
        if x < y:
            s = s[::-1]; x, y = y, x

    # Remove favored pair (now 'ab')
        score = 0
        st1 = []
        for c in s:
            if st1 and st1[-1] == 'a' and c == 'b':
                st1.pop()
                score += x
            else:
                st1.append(c)

    # Remove other pair 'ba'
        st2 = []
        for c in st1:
            if st2 and st2[-1] == 'b' and c == 'a':
                st2.pop()
                score += y
            else:
                st2.append(c)

        return score