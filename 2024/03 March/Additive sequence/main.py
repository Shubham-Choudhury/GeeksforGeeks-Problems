# Link: https://www.geeksforgeeks.org/problems/additive-sequence/1


class Solution:
    def isAdditiveSequence(self, n):
        if len(n) < 3:
            return 0

        def is_valid_number(s):
            return len(s) == 1 or s[0] != "0"

        for i in range(1, len(n) - 1):
            if not is_valid_number(n[:i]):
                continue
            for j in range(i + 1, len(n)):
                if not is_valid_number(n[i:j]):
                    continue
                num1 = int(n[:i])
                num2 = int(n[i:j])
                k = j
                while k < len(n):
                    num3 = num1 + num2
                    num3_str = str(num3)
                    if not n.startswith(num3_str, k):
                        break
                    k += len(num3_str)
                    num1, num2 = num2, num3
                    if k == len(n):
                        return 1
        return 0


if __name__ == "__main__":
    obj = Solution()
    n = "1235813"
    print(obj.isAdditiveSequence(n))
    n = "11235815"
    print(obj.isAdditiveSequence(n))
