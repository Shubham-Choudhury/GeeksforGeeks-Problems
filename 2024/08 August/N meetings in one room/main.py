# Link: https://www.geeksforgeeks.org/problems/n-meetings-in-one-room-1587115620/1


class Solution:
    def maxMeetings(self, n, start, end):
        meetings = [(end[i], start[i]) for i in range(n)]
        meetings.sort()

        count = 0
        last_end_time = 0

        for meeting in meetings:
            if meeting[1] > last_end_time:
                count += 1
                last_end_time = meeting[0]

        return count


if __name__ == "__main__":
    obj = Solution()
    n = 6
    start = [1, 3, 0, 5, 8, 5]
    end = [2, 4, 6, 7, 9, 9]

    print(obj.maxMeetings(n, start, end))
