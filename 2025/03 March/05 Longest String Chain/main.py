# Link: https://www.geeksforgeeks.org/problems/longest-string-chain/1


class Solution:
    def longestStringChain(self, words):
        words.sort(key=len)
        dp = {}
        max_chain = 1

        for word in words:
            dp[word] = 1
            for i in range(len(word)):
                prev = word[:i] + word[i + 1 :]
                if prev in dp:
                    dp[word] = max(dp[word], dp[prev] + 1)
            max_chain = max(max_chain, dp[word])

        return max_chain


if __name__ == "__main__":
    obj = Solution()
    words = ["a", "b", "ba", "bca", "bda", "bdca"]
    print(obj.longestStringChain(words))

    words = ["abc", "a", "ab"]
    print(obj.longestStringChain(words))

    words = ["abcd", "dbqca"]
    print(obj.longestStringChain(words))
