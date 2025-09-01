# Link: https://www.geeksforgeeks.org/problems/given-two-strings-find-if-first-string-is-a-subsequence-of-second/1


class Solution:
    def isSubSeq(self, s1, s2):
        n, m = len(s1), len(s2)
        i, j = 0, 0
        while i < n and j < m:
            if s1[i] == s2[j]:
                i += 1
            j += 1

        return i == n


if __name__ == "__main__":
    sol = Solution()
    s1 = "AXY"
    s2 = "YADXCP"
    result = sol.isSubSeq(s1, s2)
    print(f"Is \"{s1}\" a subsequence of \"{s2}\" ? {'YES' if result else 'NO'}")

    s1 = "gksrek"
    s2 = "geeksforgeeks"
    result = sol.isSubSeq(s1, s2)
    print(f"Is \"{s1}\" a subsequence of \"{s2}\" ? {'YES' if result else 'NO'}")
