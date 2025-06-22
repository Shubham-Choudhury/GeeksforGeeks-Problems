# Link: https://www.geeksforgeeks.org/problems/minimum-sum4058/1


class Solution:
    def addString(self, s1: str, s2: str) -> str:
        i = len(s1) - 1
        j = len(s2) - 1
        carry = 0
        res = []

        while i >= 0 or j >= 0 or carry > 0:
            total = carry
            if i >= 0:
                total += int(s1[i])
                i -= 1
            if j >= 0:
                total += int(s2[j])
                j -= 1

            res.append(str(total % 10))
            carry = total // 10

        while len(res) > 1 and res[-1] == "0":
            res.pop()

        return "".join(reversed(res))

    def minSum(self, arr):
        count = [0] * 10
        for num in arr:
            count[num] += 1

        s1, s2 = "", ""
        firstNum = True

        for digit in range(10):
            while count[digit] > 0:
                if firstNum:
                    if not (s1 == "" and digit == 0):
                        s1 += str(digit)
                    firstNum = False
                else:
                    if not (s2 == "" and digit == 0):
                        s2 += str(digit)
                    firstNum = True
                count[digit] -= 1

        if s1 == "":
            s1 = "0"
        if s2 == "":
            s2 = "0"

        return self.addString(s1, s2)


if __name__ == "__main__":
    sol = Solution()
    arr = [6, 8, 4, 5, 2, 3]
    result = sol.minSum(arr)
    print(f"Minimum sum: {result}")

    arr = [5, 3, 0, 7, 4]
    result = sol.minSum(arr)
    print(f"Minimum sum: {result}")

    arr = [9, 4]
    result = sol.minSum(arr)
    print(f"Minimum sum: {result}")
