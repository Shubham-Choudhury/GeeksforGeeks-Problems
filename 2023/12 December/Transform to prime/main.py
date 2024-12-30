# Link: https://www.geeksforgeeks.org/problems/transform-to-prime4635/1


class Solution:
    def minNumber(self, arr, n):
        # code here
        def isprime(n):
            for i in range(2, int(n**0.5) + 1):
                if n % i == 0:
                    return False
            return True

        val = sum(arr)
        if isprime(val):
            return 0
        right = val
        left = val
        while True:
            right += 1
            left -= 1
            if isprime(right):
                return right - val


if __name__ == "__main__":
    obj = Solution()
    arr = [2, 4, 6, 8, 12]
    n = len(arr)
    print(obj.minNumber(arr, n))

    arr = [1, 5, 7]
    n = len(arr)
    print(obj.minNumber(arr, n))
