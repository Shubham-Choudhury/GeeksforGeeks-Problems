# Link: https://www.geeksforgeeks.org/problems/check-if-a-number-is-divisible-by-83957/1


class Solution:
    def DivisibleByEight(self, s):
        n = len(s)

        if len(s) <= 3:

            t = int(s)

            if t % 8 == 0:
                return 1
            else:
                return -1

        else:
            t = int(s[n - 3 :])

            if t % 8 == 0:
                return 1
            else:
                return -1


if __name__ == "__main__":
    obj = Solution()
    s = "16"
    print(obj.DivisibleByEight(s))
    s = "54141111648421214584416464555"
    print(obj.DivisibleByEight(s))
