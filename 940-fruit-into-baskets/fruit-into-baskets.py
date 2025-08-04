class Solution(object):
    def totalFruit(self, fruits):
        """
        :type fruits: List[int]
        :rtype: int
        """
        left = 0
        res = 0
        basket = defaultdict(int)

        for right in range(len(fruits)):
            item = fruits[right]
            basket[item] = basket.get(item, 0) + 1

            while len(basket) > 2:
                basket[fruits[left]] -= 1
                if basket[fruits[left]] == 0:
                    del basket[fruits[left]]
                left += 1
            
            res = max(res, right - left + 1)
        
        return res
            


        