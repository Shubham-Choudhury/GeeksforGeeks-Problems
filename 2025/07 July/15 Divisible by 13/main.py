# Link: https://www.geeksforgeeks.org/problems/divisible-by-13/1


class Solution:
    def divBy13(self, s):
        length = len(s)

        if length == 1 and s[0] == "0":
            return True

        if length % 3 == 1:
            s += "00"
            length += 2
        elif length % 3 == 2:
            s += "0"
            length += 1

        sum_ = 0
        p = 1

        i = length - 1
        while i >= 0:
            group = 0
            group += int(s[i])
            i -= 1
            group += int(s[i]) * 10
            i -= 1
            group += int(s[i]) * 100
            i -= 1

            sum_ += group * p
            p *= -1

        sum_ = abs(sum_)
        return sum_ % 13 == 0


if __name__ == "__main__":
    sol = Solution()
    s = "2911285"
    result = sol.divBy13(s)
    print(f"{s} is {'divisible' if result else 'not divisible'} by 13")

    s = "27"
    result = sol.divBy13(s)
    print(f"{s} is {'divisible' if result else 'not divisible'} by 13")
