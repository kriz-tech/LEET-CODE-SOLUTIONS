from collections import deque, defaultdict
import bisect
from dataclasses import dataclass

@dataclass(frozen=True)
class Packet:
    source: int
    destination: int
    timestamp: int

class Router:
    def __init__(self, memoryLimit: int):
        self.memoryLimit = memoryLimit
        self.packetQueue = deque()            # store Packet objects
        self.unique = set()                   # for detecting duplicates
        self.dest_timestamps = defaultdict(list)  # destination -> list of timestamps
        self.forwarded_count = defaultdict(int)   # destination -> how many forwarded

    def addPacket(self, source: int, destination: int, timestamp: int) -> bool:
        pkt = Packet(source, destination, timestamp)
        if pkt in self.unique:
            return False
        if len(self.packetQueue) == self.memoryLimit:
            self.forwardPacket()
        self.packetQueue.append(pkt)
        self.unique.add(pkt)
        self.dest_timestamps[destination].append(timestamp)
        return True

    def forwardPacket(self):
        if not self.packetQueue:
            return []
        pkt = self.packetQueue.popleft()
        self.unique.remove(pkt)
        # update forwarded count for that destination
        self.forwarded_count[pkt.destination] += 1
        return [pkt.source, pkt.destination, pkt.timestamp]

    def getCount(self, destination: int, startTime: int, endTime: int) -> int:
        if destination not in self.dest_timestamps:
            return 0
        timestamps = self.dest_timestamps[destination]
        # skip the first forwarded_count[destination] timestamps
        start_idx = self.forwarded_count.get(destination, 0)
        # find first index >= startTime
        lo = bisect.bisect_left(timestamps, startTime, lo=start_idx)
        # find last index <= endTime → via upper_bound
        hi = bisect.bisect_right(timestamps, endTime, lo=start_idx)
        return hi - lo
