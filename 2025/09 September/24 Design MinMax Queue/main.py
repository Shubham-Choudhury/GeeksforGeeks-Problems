# Link: https://www.geeksforgeeks.org/problems/design-minmax-queue/1

from collections import deque


class SpecialQueue:
    def __init__(self):
        self.q1 = deque()
        self.q2 = deque()

    def enqueue(self, x):
        self.q1.append(x)
        while self.q2 and self.q2[-1] > x:
            self.q2.pop()
        self.q2.append(x)

    def dequeue(self):
        if not self.q1:
            print("Queue is empty")
            return
        frontVal = self.q1.popleft()
        if frontVal == self.q2[0]:
            self.q2.popleft()

    def getMin(self):
        if not self.q1:
            print("Queue is empty")
            return -1
        return self.q2[0]

    def getFront(self):
        if not self.q1:
            print("Queue is empty")
            return -1
        return self.q1[0]

    def getMax(self):
        if not self.q1:
            print("Queue is empty")
            return -1
        return max(self.q1)


if __name__ == "__main__":
    sq = SpecialQueue()
    sq.enqueue(4)
    sq.enqueue(2)
    print(f"Front element: {sq.getFront()}")
    print(f"Minimum element: {sq.getMin()}")
    sq.dequeue()
    print(f"Maximum element: {sq.getMax()}")

    sq = SpecialQueue()
    sq.enqueue(3)
    print(f"Minimum element: {sq.getMin()}")
    sq.enqueue(5)
    print(f"Maximum element: {sq.getMax()}")
