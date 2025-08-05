# Link: https://www.geeksforgeeks.org/problems/string-palindromic-ignoring-spaces4723/1


class Solution:
    def isPalinSent(self, s):
        i, j = 0, len(s) - 1

        while i < j:
            if not s[i].isalnum():
                i += 1
            elif not s[j].isalnum():
                j -= 1
            elif s[i].lower() == s[j].lower():
                i += 1
                j -= 1
            else:
                return False

        return True


if __name__ == "__main__":
    sol = Solution()
    s = "Too hot to hoot"
    result = sol.isPalinSent(s)
    print(f"Is the sentence '{s}' a palindrome? {result}")

    s = "Abc 012..## 10cbA"
    result = sol.isPalinSent(s)
    print(f"Is the sentence '{s}' a palindrome? {result}")

    s = "ABC $. def01ASDF"
    result = sol.isPalinSent(s)
    print(f"Is the sentence '{s}' a palindrome? {result}")
