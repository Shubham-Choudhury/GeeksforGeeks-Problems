# Link: https://www.geeksforgeeks.org/problems/smallest-number5829/1


class Solution:
    def smallestNumber(self, s, d):
        res = []
        first = True
        while d > 0:
            if first:
                start = 1
            else:
                start = 0
            first = False
            for i in range(start, 10):
                if 0 <= s - i <= 9 * (d - 1):
                    res.append(i)
                    s -= i
                    d -= 1
                    break
            else:
                return -1
        k = 0
        for i in res:
            k = k * 10 + i
        return k


if __name__ == "__main__":
    obj = Solution()
    s = 9
    d = 2
    print(obj.smallestNumber(s, d))
    s = 20
    d = 3
    print(obj.smallestNumber(s, d))
