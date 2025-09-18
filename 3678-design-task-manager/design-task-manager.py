import heapq

class TaskManager:

    def __init__(self, tasks: list[list[int]]):
        self.task_map = {}  # Maps taskId to (userId, priority)
        self.max_heap = []  # Max-heap to get the highest priority task
        for userId, taskId, priority in tasks:
            self.add(userId, taskId, priority)

    def add(self, userId: int, taskId: int, priority: int) -> None:
        """Add a new task."""
        self.task_map[taskId] = (userId, priority)
        heapq.heappush(self.max_heap, (-priority, -taskId, userId))

    def edit(self, taskId: int, newPriority: int) -> None:
        """Edit the priority of an existing task."""
        if taskId in self.task_map:
            userId, _ = self.task_map[taskId]
            self.task_map[taskId] = (userId, newPriority)
            heapq.heappush(self.max_heap, (-newPriority, -taskId, userId))

    def rmv(self, taskId: int) -> None:
        """Remove a task."""
        if taskId in self.task_map:
            del self.task_map[taskId]

    def execTop(self) -> int:
        """Execute and remove the task with the highest priority."""
        while self.max_heap:
            neg_priority, neg_taskId, userId = self.max_heap[0]
            taskId = -neg_taskId
            if taskId in self.task_map and self.task_map[taskId] == (userId, -neg_priority):
                heapq.heappop(self.max_heap)
                del self.task_map[taskId]
                return userId
            else:
                heapq.heappop(self.max_heap)
        return -1  # No tasks available
