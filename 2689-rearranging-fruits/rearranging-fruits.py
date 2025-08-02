class Solution(object):
    def minCost(self, basket1, basket2):
        """
        :type basket1: List[int]
        :type basket2: List[int]
        :rtype: int
        """
        count1 = Counter(basket1)
        count2 = Counter(basket2)
        all_keys = set(count1.keys()).union(count2.keys())

        # Check for impossible case
        for key in all_keys:
            if (count1[key] + count2[key]) % 2 != 0:
                return -1

        # Prepare excess items to swap
        excess1 = []
        excess2 = []
        for key in all_keys:
            diff = count1[key] - count2[key]
            if diff > 0:
                excess1.extend([key] * (diff // 2))
            elif diff < 0:
                excess2.extend([key] * (-diff // 2))

        # Sort for greedy pairing
        excess1.sort()
        excess2.sort(reverse=True)
        min_fruit = min(min(basket1), min(basket2))

        # Swap the cheapest way
        total_cost = 0
        for a, b in zip(excess1, excess2):
            total_cost += min(min(a, b), 2 * min_fruit)

        return total_cost
        