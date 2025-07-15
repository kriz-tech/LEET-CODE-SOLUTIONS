class Solution(object):
    def isValid(self, word):
        """
        :type word: str
        :rtype: bool
        """
        if len(word) < 3 or not word.isalnum():
            return False
        v_count, c_count = 0, 0
        count = 0
        for letter in word:
            if letter.isalnum():
                if letter.isalpha():
                    if letter in 'aeiouAEIOU':
                        v_count += 1
                    else:
                        c_count += 1
                count += 1

        count += v_count + c_count            
        return count > 2 and v_count > 0 and c_count > 0