# Link: https://www.geeksforgeeks.org/problems/check-frequencies4211/1


class Solution:
    def sameFreq(self, s):
        freqs = {}

        for i in s:
            freqs[i] = freqs.get(i, 0) + 1

        minFreq = min(freqs.values())
        maxFreq = max(freqs.values())

        if len(freqs) == 1 or maxFreq == minFreq:
            return True

        if maxFreq - minFreq > 1:
            return False

        maxFreqCount = 0
        minFreqCount = 0
        for i in freqs.values():
            if i != minFreq and i != maxFreq:
                return False
            if i == minFreq:
                minFreqCount += 1
            else:
                maxFreqCount += 1

        if maxFreqCount != 1:
            return False

        return True


if __name__ == "__main__":
    obj = Solution()
    s = "xyyz"
    print(obj.sameFreq(s))
    s = "xxxxyyzz"
    print(obj.sameFreq(s))
    s="xxyyz"
    print(obj.sameFreq(s))
