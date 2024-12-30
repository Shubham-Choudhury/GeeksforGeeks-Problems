# Link: https://www.geeksforgeeks.org/problems/count-numbers-containing-43022/1


class Solution:
    def countNumberswith4(self, n: int) -> int:
        def has_digit_4(x):
            while x > 0:
                if x % 10 == 4:
                    return True
                x = x // 10
            return False

        count = 0
        for i in range(4, n + 1):
            if has_digit_4(i):
                count += 1

        return count


if __name__ == "__main__":
    obj = Solution()
    n = 9
    print(obj.countNumberswith4(n))
    n = 14
    print(obj.countNumberswith4(n))
