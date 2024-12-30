# Link: https://www.geeksforgeeks.org/problems/integral-points-in-triangle5026/1

from math import gcd

class Solution:
    def getEdgePoint(self, x1, y1, x2, y2):
        if x1 == x2:
            return abs(y2 - y1) - 1
        if y1 == y2:
            return abs(x1 - x2) - 1
        return gcd(abs(x1 - x2), abs(y1 - y2)) - 1

    def InternalCount(self, p, q, r):
        x1, y1 = p
        x2, y2 = q
        x3, y3 = r
        points = (
            self.getEdgePoint(x1, y1, x2, y2)
            + self.getEdgePoint(x2, y2, x3, y3)
            + self.getEdgePoint(x3, y3, x1, y1)
            + 3
        )
        area = abs(x1 * (y2 - y3) + x2 * (y3 - y1) + x3 * (y1 - y2))
        return (area - points + 2) // 2


if __name__ == "__main__":
    obj = Solution()

    p1 = [0, 0]
    q1 = [0, 5]
    r1 = [5, 0]
    print(obj.InternalCount(p1, q1, r1))

    p2 = [62, -3]
    q2 = [5, -45]
    r2 = [-19, -23]
    print(obj.InternalCount(p2, q2, r2))
