# Link: https://www.geeksforgeeks.org/problems/the-palindrome-pattern3900/1


class Solution:
    def pattern(self, arr):
        n = len(arr)

        def is_palindrome(lst):
            return lst == lst[::-1]

        for i in range(n):
            if is_palindrome(arr[i]):
                return str(i) + " R"

        transposed_arr = list(zip(*arr))

        for j in range(n):
            if is_palindrome(transposed_arr[j]):
                return str(j) + " C"

        return "-1"


if __name__ == "__main__":
    obj = Solution()
    arr = [[1, 0, 0], [0, 1, 0], [1, 1, 0]]
    print(obj.pattern(arr))

    arr = [[1, 0]]
    print(obj.pattern(arr))
