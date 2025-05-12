# Link: https://www.geeksforgeeks.org/problems/meeting-rooms-iii/1


import heapq
from collections import defaultdict


class Solution:
    def mostBooked(self, n, meetings):
        meetings.sort()

        engaged = []

        unused = list(range(n))
        heapq.heapify(unused)

        freq = defaultdict(int)

        for start, end in meetings:
            while engaged and engaged[0][0] <= start:
                end_time, room = heapq.heappop(engaged)
                heapq.heappush(unused, room)

            if unused:
                room = heapq.heappop(unused)
                freq[room] += 1
                heapq.heappush(engaged, (end, room))
            else:
                end_time, room = heapq.heappop(engaged)
                duration = end - start
                new_end = end_time + duration
                freq[room] += 1
                heapq.heappush(engaged, (new_end, room))

        max_room = 0
        for i in range(1, n):
            if freq[i] > freq[max_room]:
                max_room = i

        return max_room


if __name__ == "__main__":
    obj = Solution()
    n = 2
    meetings = [[0, 6], [2, 3], [3, 7], [4, 8], [6, 8]]
    print(obj.mostBooked(n, meetings))

    n = 4
    meetings = [[0, 8], [1, 4], [3, 4], [2, 3]]
    print(obj.mostBooked(n, meetings))
