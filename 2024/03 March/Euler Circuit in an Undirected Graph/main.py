# Link: https://www.geeksforgeeks.org/problems/euler-circuit-in-a-directed-graph/1


class Solution:
    def isEularCircuitExist(self, v, adj):
        c = 0
        for i in adj:
            if len(i) & 1:
                c += 1
        if c < 2:
            return 1
        return 0


if __name__ == "__main__":
    obj = Solution()
    adj = [[1, 2], [2, 3], [3, 1]]
    print(obj.isEularCircuitExist(3, adj))
    adj = [[1, 2], [2, 3], [3, 1], [3, 4], [4, 3]]
    print(obj.isEularCircuitExist(4, adj))
