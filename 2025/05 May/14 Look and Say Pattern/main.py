# Link: https://www.geeksforgeeks.org/problems/decode-the-pattern1138/1


class Solution:
    def countAndSay(self, n):
        if n == 1:
            return "1"

        curr = "1"

        for i in range(2, n + 1):
            nextStr = ""
            cnt = 1

            for j in range(1, len(curr)):
                if curr[j] == curr[j - 1]:
                    cnt += 1
                else:
                    nextStr += str(cnt) + curr[j - 1]
                    cnt = 1

            nextStr += str(cnt) + curr[-1]
            curr = nextStr

        return curr


if __name__ == "__main__":
    obj = Solution()
    n = 5
    print(obj.countAndSay(n))
    n = 3
    print(obj.countAndSay(n))
