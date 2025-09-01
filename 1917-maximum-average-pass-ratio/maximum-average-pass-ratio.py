import heapq
class Solution:
    def maxAverageRatio(self, c: List[List[int]], es: int) -> float:
        def gain(p, t):
            return (p + 1) / (t + 1) - p / t
        heap = [(-gain(p, t), p, t) for p, t in c]
        heapq.heapify(heap)

        for _ in range(es):
            g, p, t = heapq.heappop(heap)
            p, t = p + 1, t + 1
            heapq.heappush(heap, (-gain(p, t), p, t))
        
        return sum(p / t for _, p, t in heap) / len(heap)
        