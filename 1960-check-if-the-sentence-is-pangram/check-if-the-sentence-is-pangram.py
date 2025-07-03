class Solution(object):
    def checkIfPangram(self, sentence):
        """
        :type sentence: str
        :rtype: bool
        """
        return set(string.ascii_lowercase).issubset(set(sentence))
        