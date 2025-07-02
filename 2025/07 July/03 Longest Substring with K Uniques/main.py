# Link: https://www.geeksforgeeks.org/problems/longest-k-unique-characters-substring0853/1


class Solution:
    def longestKSubstr(self, s, k):
        n = len(s)

        vec = [[0] * 26 for _ in range(n)]

        for i in range(n):
            vec[i][ord(s[i]) - ord("a")] += 1
            if i > 0:
                for j in range(26):
                    vec[i][j] += vec[i - 1][j]

        ans = -1

        for i in range(n):
            low, high = i, n - 1
            currAns = -1

            while low <= high:
                mid = (low + high) // 2
                freq = vec[mid][:]

                if i > 0:
                    for j in range(26):
                        freq[j] -= vec[i - 1][j]

                count = sum(1 for f in freq if f > 0)

                if count == k:
                    currAns = mid - i + 1
                    low = mid + 1
                elif count < k:
                    low = mid + 1
                else:
                    high = mid - 1

            if currAns != -1:
                ans = max(ans, currAns)

        return ans


if __name__ == "__main__":
    sol = Solution()
    s = "aabacbebebe"
    k = 3
    result = sol.longestKSubstr(s, k)
    print(f"Length of the longest substring with {k} unique characters: {result}")

    s = "aaaa"
    k = 2
    result = sol.longestKSubstr(s, k)
    print(f"Length of the longest substring with {k} unique characters: {result}")

    s = "aabaaab"
    k = 2
    result = sol.longestKSubstr(s, k)
    print(f"Length of the longest substring with {k} unique characters: {result}")
