# Link: https://www.geeksforgeeks.org/problems/maximize-partitions-in-a-string/1


class Solution:
    def maxPartitions(self, s: str) -> int:
        cnt = 0
        n = len(s)
        mp = {char: i for i, char in enumerate(s)}

        ans = -1
        for i in range(n):
            ans = max(ans, mp[s[i]])

            if ans == i:
                cnt += 1
        return cnt


if __name__ == "__main__":
    sol = Solution()
    s = "acbbcc"
    print(sol.maxPartitions(s))

    s = "ababcbacadefegdehijhklij"
    print(sol.maxPartitions(s))

    s = "aaa"
    print(sol.maxPartitions(s))
