import collections
from sortedcontainers import SortedList

class FoodRatings:
    def __init__(self, foods, cuisines, ratings):
        # cuisine → sorted list of (-rating, foodName)
        self.cuisine_foods = collections.defaultdict(SortedList)
        # foodName → (rating, cuisine)
        self.food_info = {}

        for food, cuisine, rating in zip(foods, cuisines, ratings):
            self.food_info[food] = (rating, cuisine)
            # Use negative rating so higher ratings come first
            self.cuisine_foods[cuisine].add((-rating, food))

    def changeRating(self, food: str, newRating: int) -> None:
        oldRating, cuisine = self.food_info[food]
        self.food_info[food] = (newRating, cuisine)
        self.cuisine_foods[cuisine].remove((-oldRating, food))
        self.cuisine_foods[cuisine].add((-newRating, food))

    def highestRated(self, cuisine: str) -> str:
        # First element in sorted list is the one with max rating, and among ties, lex smallest
        return self.cuisine_foods[cuisine][0][1]
