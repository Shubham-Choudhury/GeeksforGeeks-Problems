# Link: https://www.geeksforgeeks.org/problems/smith-number4132/1


class Solution:
    def smithNum(self, n):
        # code here
        def sum_digits(n):
            s = 0
            while n > 0:
                s += n % 10
                n //= 10
            return s

        def sums(n):
            s = 0
            i = 2
            m = n
            while i <= n:
                if n % i == 0 and i != m:
                    s += sum_digits(i)
                    n //= i
                else:
                    i += 1
            return s

        return int(sum_digits(n) == sums(n))


if __name__ == "__main__":
    obj = Solution()
    print(obj.smithNum(4))
    print(obj.smithNum(378))
