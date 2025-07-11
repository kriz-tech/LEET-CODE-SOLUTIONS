class Solution(object):
    def mostBooked(self, n, meetings):
        """
        :type n: int
        :type meetings: List[List[int]]
        :rtype: int
        """
        meetings.sort()

        available_rooms = list(range(n))
        heapq.heapify(available_rooms)

        busy_rooms = []

        meeting_count = [0] * n

        for start, end in meetings:

            while busy_rooms and busy_rooms[0][0] <= start:
                end_time, room = heapq.heappop(busy_rooms)
                heapq.heappush(available_rooms, room)

            if available_rooms:
                room = heapq.heappop(available_rooms)
                heapq.heappush(busy_rooms, (end, room))
                meeting_count[room] += 1
            else:
                end_time, room = heapq.heappop(busy_rooms)
                duration = end - start
                new_end = end_time + duration
                heapq.heappush(busy_rooms, (new_end, room))
                meeting_count[room] += 1

        max_meetings = max(meeting_count)
        for i in range(n):
            if meeting_count[i] == max_meetings:
                return i
        