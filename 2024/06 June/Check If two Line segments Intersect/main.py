# Link: https://www.geeksforgeeks.org/problems/check-if-two-line-segments-intersect0017/1


class Solution:
    def doIntersect(self, p1, q1, p2, q2):
        m1 = (q1[1] - p1[1]) / (q1[0] - p1[0])
        m2 = (q2[1] - p2[1]) / (q2[0] - p2[0])
        if m1 == m2:
            return "false"

        chk211 = (p2[1] - p1[1]) - m1 * (p2[0] - p1[0]) > 0
        chk212 = (q2[1] - p1[1]) - m1 * (q2[0] - p1[0]) > 0
        chk121 = (p1[1] - p2[1]) - m2 * (p1[0] - p2[0]) > 0
        chk122 = (q1[1] - p2[1]) - m2 * (q1[0] - p2[0]) > 0

        if (
            (chk211 and chk212)
            or (not chk211 and not chk212)
            or (chk121 and chk122)
            or (not chk121 and not chk122)
        ):
            return "false"
        return "true"


if __name__ == "__main__":
    obj = Solution()
    print(obj.doIntersect([1, 1], [10, 1], [1, 2], [10, 2]))
    print(obj.doIntersect([10, 0], [0, 10], [0, 0], [10, 10]))
