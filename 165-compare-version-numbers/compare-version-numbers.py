class Solution(object):
    def compareVersion(self, version1, version2):
        """
        :type version1: str
        :type version2: str
        :rtype: int
        """
        v1 = list(map(int, version1.split('.')))
        v2 = list(map(int, version2.split('.')))

        while v1 and v1[-1] == 0:
            v1.pop()
        while v2 and v2[-1] == 0:
            v2.pop()
            
        for a, b in zip(v1, v2):
            if a < b:
                return -1
            elif a > b:
                return 1

        if len(v1) < len(v2):
            return -1
        elif len(v1) > len(v2):
            return 1
        else:
            return 0