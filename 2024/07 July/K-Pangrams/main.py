# Link: https://www.geeksforgeeks.org/problems/k-pangrams0909/1


class Solution:
    def kPangram(self, string, k):
        n = len(string)
        spaces = string.count(" ")
        m = set(string) - {" "}

        if 26 - len(m) <= k and 26 - len(m) <= n - spaces and n - spaces >= 26:
            return True
        return False


if __name__ == "__main__":
    obj = Solution()
    str1 = "the quick brown fox jumps over the lazy dog"
    k1 = 0
    print(obj.kPangram(str1, k1))

    str2 = "aaaaaaaaaaaaaaaaaaaaaaaaaa"
    k2 = 25
    print(obj.kPangram(str2, k2))

    str3 = "a b c d e f g h i j k l m"
    k3 = 20
    print(obj.kPangram(str3, k3))
