# Link: https://www.geeksforgeeks.org/problems/largest-number-formed-from-an-array1117/1

from functools import cmp_to_key


class Solution:
    def myCompare(self, s1, s2):
        if s1 + s2 > s2 + s1:
            return -1
        else:
            return 1

    def findLargest(self, arr):

        numbers = [str(ele) for ele in arr]

        numbers.sort(key=cmp_to_key(self.myCompare))

        if numbers[0] == "0":
            return "0"

        res = "".join(numbers)

        return res


if __name__ == "__main__":
    solution = Solution()
    arr = [3, 30, 34, 5, 9]
    result = solution.findLargest(arr)
    print(f"Largest number formed: {result}")

    arr = [54, 546, 548, 60]
    result = solution.findLargest(arr)
    print(f"Largest number formed: {result}")

    arr = [3, 4, 6, 5, 9]
    result = solution.findLargest(arr)
    print(f"Largest number formed: {result}")
