# Link: https://www.geeksforgeeks.org/problems/count-palindrome-sub-strings-of-a-string0652/1


class Solution:
    def countPS(self, s):
        n = len(s)
        count = 0

        def expandAroundCenter(left: int, right: int):
            nonlocal count
            while left >= 0 and right < n and s[left] == s[right]:
                if right - left + 1 >= 2:
                    count += 1
                left -= 1
                right += 1

        for i in range(n):
            expandAroundCenter(i, i)
            expandAroundCenter(i, i + 1)

        return count


if __name__ == "__main__":
    obj = Solution()
    s = "abaab"
    print(obj.countPS(s))

    s = "aaa"
    print(obj.countPS(s))

    s = "abbaeae"
    print(obj.countPS(s))
