# Link: https://www.geeksforgeeks.org/problems/substrings-of-length-k-with-k-1-distinct-elements/1


class Solution:
    def substrCount(self, s, k):
        if k > len(s):
            return 0

        n = len(s)
        cnt = [0] * 26
        ans = 0

        for i in range(k - 1):
            cnt[ord(s[i]) - ord("a")] += 1

        for i in range(k - 1, n):

            cnt[ord(s[i]) - ord("a")] += 1

            distinctCnt = sum(1 for x in cnt if x > 0)
            if distinctCnt == k - 1:
                ans += 1

            cnt[ord(s[i - k + 1]) - ord("a")] -= 1

        return ans


if __name__ == "__main__":
    sol = Solution()
    s = "abcc"
    k = 2
    result = sol.substrCount(s, k)
    print(f"Number of substrings of length {k} with {k-1} distinct elements: {result}")

    s = "aabab"
    k = 3
    result = sol.substrCount(s, k)
    print(f"Number of substrings of length {k} with {k-1} distinct elements: {result}")
