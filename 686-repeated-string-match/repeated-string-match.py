class Solution(object):
    def repeatedStringMatch(self, a, b):
        """
        :type a: str
        :type b: str
        :rtype: int
        """
        count = 1
        repeated = a
        while(len(repeated) < len(b)):
            repeated += a
            count += 1

        if b in repeated:
            return count
        if b in repeated + a:
            return count+1
        return -1
        