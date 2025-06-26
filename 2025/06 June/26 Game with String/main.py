# Link: https://www.geeksforgeeks.org/problems/game-with-string4100/1


class Solution:
    def minValue(self, s, k):
        n = len(s)

        alphabetCount = [0] * 26

        for c in s:
            alphabetCount[ord(c) - ord("a")] += 1

        maxi = max(alphabetCount)

        freq = [0] * (maxi + 1)

        for count in alphabetCount:
            if count > 0:
                freq[count] += 1

        maxFreq = maxi

        while k > 0 and maxFreq > 0:
            count_at_max = freq[maxFreq]
            if count_at_max == 0:
                maxFreq -= 1
                continue

            if count_at_max <= k:
                k -= count_at_max
                freq[maxFreq - 1] += count_at_max
                freq[maxFreq] = 0
                maxFreq -= 1
            else:
                freq[maxFreq] -= k
                freq[maxFreq - 1] += k
                k = 0

        result = 0
        for i in range(1, len(freq)):
            result += i * i * freq[i]

        return result


if __name__ == "__main__":
    sol = Solution()
    s = "abbccc"
    k = 2
    print(sol.minValue(s, k))

    s = "aaab"
    k = 2
    print(sol.minValue(s, k))
