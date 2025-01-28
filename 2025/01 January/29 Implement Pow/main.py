# Link: https://www.geeksforgeeks.org/problems/powx-n/1


class Solution:
    def power(self, b: float, e: int) -> float:
        if e == 0:
            return 1

        N = e
        if N < 0:
            b = 1 / b
            N = -N

        result = 1
        while N > 0:
            if N % 2 == 1:
                result *= b
            b *= b
            N //= 2

        return result


if __name__ == "__main__":
    object = Solution()
    b = 3.00000
    e = 5
    print(object.power(b, e))

    b = 0.55000
    e = 3
    print(object.power(b, e))

    b = -0.67000
    e = 7
    print(object.power(b, e))
