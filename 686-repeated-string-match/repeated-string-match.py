class Solution(object):
    def repeatedStringMatch(self, a, b):
        """
        :type a: str
        :type b: str
        :rtype: int
        """
        import math
        nrep = int(math.ceil(len(b) / len(a)))
        if b in a * nrep:
            return nrep
        elif b in a * (nrep + 1):
            return nrep + 1
        elif b in a * (nrep + 2):
            return nrep + 2
        else:
            return -1
        
        