# Link: https://www.geeksforgeeks.org/problems/count-palindrome-sub-strings-of-a-string0652/1


class Solution:
    def countPS(self, s):
        n = len(s)
        count = 0

        for i in range(len(s)):
            left = i - 1
            right = i + 1
            while left >= 0 and right < n:
                if s[left] == s[right]:
                    count += 1
                else:
                    break
                left -= 1
                right += 1

        for i in range(len(s)):
            left = i
            right = i + 1
            while left >= 0 and right < n:
                if s[left] == s[right]:
                    count += 1
                else:
                    break
                left -= 1
                right += 1

        return count


if __name__ == "__main__":
    sol = Solution()
    s = "abaab"
    result = sol.countPS(s)
    print(result)

    s = "aaa"
    result = sol.countPS(s)
    print(result)

    s = "abbaeae"
    result = sol.countPS(s)
    print(result)
